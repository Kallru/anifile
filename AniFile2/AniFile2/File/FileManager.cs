using System;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Xml;
using System.Windows.Forms;

namespace AniFile2
{
    public class FileManager
    {
        private string m_fileHeader = "Copyright(c) 2010 made by Shin Hwi Jae";
        private float m_version = 1.0f;

        public string FileHeader{ get { return m_fileHeader; } }
        public float Version { get { return m_version; } }
        public string FileName { get; set; }

        public FileManager( string fileName )
        {
            FileName = fileName;
        }

        public void Load( TreeNodeCollection nodes )
        {
            FileStream fileStream = File.Open( FileName, FileMode.Open );
            if( Path.GetExtension( FileName ) == ".xml" )
            {
                XmlLoad( fileStream, nodes );
            }
            else
            {
                OldDataLoad( fileStream, nodes );
            }
        }

        public void Save( TreeNodeCollection nodes )
        {
            XmlWriterSettings settings = new XmlWriterSettings();
            settings.Indent = true;
            settings.Encoding = Encoding.Unicode;
            settings.ConformanceLevel = ConformanceLevel.Auto;

            XmlWriter writer = XmlWriter.Create( FileName, settings );
            writer.WriteStartElement( "Root" );
            writer.WriteElementString( "header", m_fileHeader );
            writer.WriteElementString( "version", m_version.ToString() );
            
            writer.WriteStartElement( "Data" );

            NodesSave( writer, nodes );

            writer.WriteFullEndElement();

            writer.Close();
        }

        private void NodesSave( XmlWriter writer, TreeNodeCollection nodes )
        {
            foreach( AniFileNode node in nodes )
            {
                writer.WriteStartElement( "Node" );
                writer.WriteAttributeString( "name", node.Text );

                foreach( KeyValuePair<string, uint> item in node.Files )
                {
                    writer.WriteStartElement( "Item" );
                    writer.WriteAttributeString( "name", item.Key );
                    writer.WriteAttributeString( "count", item.Value.ToString() );
                    writer.WriteEndElement();
                }

                NodesSave( writer, node.Nodes );
                writer.WriteEndElement();
            }
        }

        private void XmlLoad( FileStream fileStream, TreeNodeCollection nodes )
        {
            nodes.Clear();

            XmlDocument doc = new XmlDocument();
            doc.Load( fileStream );

            XmlElement root = doc.DocumentElement;
            
            foreach( XmlNode node in root.ChildNodes )
            {
                switch( node.Name )
                {
                    case "header":
                        if( m_fileHeader != node.InnerText )
                        {
                            MessageBox.Show( "잘못된 파일입니다." );
                            return;
                        }
                        break;
                    case "version":
                        if( m_version != Convert.ToSingle( node.InnerText ) )
                        {
                            MessageBox.Show( "파일 버전이 다릅니다." );
                            return;
                        }
                        break;
                    case "Data":
                        {
                            AniFileNode aniParent = new AniFileNode( "" );
                            NodeLoad( node, aniParent );

                            foreach( AniFileNode aniNode in aniParent.Nodes )
                            {
                                nodes.Add( aniNode );
                            }
                        }
                        break;
                }
            }
        }

        private void NodeLoad( XmlNode parent, AniFileNode aniParent )
        {
            foreach( XmlNode child in parent.ChildNodes )
            {
                switch( child.Name )
                {
                    case "Node":
                        XmlAttribute attribute = child.Attributes[ "name" ];
                        AniFileNode newAniNode = new AniFileNode( attribute.Value );
                        NodeLoad( child, newAniNode );
                        aniParent.Nodes.Add( newAniNode );
                        break;
                    case "Item":
                        XmlAttribute name = child.Attributes[ "name" ];
                        XmlAttribute count = child.Attributes[ "count" ];
                        aniParent.Files.Add( name.Value, Convert.ToUInt32( count.Value ) );
                        break;
                }
            }
        }

        private void OldDataLoad( FileStream fileStream, TreeNodeCollection nodes )
        {
            AniFileNode node = new AniFileNode( "예전데이터" );

            StreamReader streamReader = new StreamReader( fileStream, Encoding.Default );

            while( !streamReader.EndOfStream )
            {
                string line = streamReader.ReadLine();
                string [] split = line.Split( '_' );

                if( split.Length > 1 )
                {
                    node.Files[ split[ 0 ] ] = Convert.ToUInt32( split[ split.Length - 1 ] );
                }
            }

            nodes.Add( node );
        }
    }
}
