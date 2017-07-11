using System;
using System.Collections.Generic;
using System.Text;
using System.Windows.Forms;

namespace AniFile2
{
    public class AniFileNode : TreeNode
    {
        private Dictionary<string, uint> m_files = new Dictionary<string, uint>();

        public Dictionary<string, uint> Files
        {
            get { return m_files; }
        }

        public AniFileNode( string text )
        {
            Text = text;
        }

        public string GetNewFolderName()
        {
            string defualtName = "새 폴더";
            int count = 0;
            foreach( AniFileNode node in Nodes )
            {
                string replace = node.Text.Replace( defualtName, "" );
                if( replace.Length == 0 )
                {
                    ++count;
                }
                else
                {
                    try
                    {
                        int number = Convert.ToInt32( replace );
                        count = System.Math.Max( count, number + 1 );
                    }
                    catch( FormatException e )
                    {
                    }
                }
            }

            if( count > 0 )
            {
                defualtName += count.ToString();
            }

            return defualtName;
        }

        public string GetNewFileName()
        {
            string defualtName = "제목없음";
            int count = 0;
            foreach( KeyValuePair<string,uint> value in m_files )
            {
                string replace = value.Key.Replace( defualtName, "" );
                if( replace.Length == 0 )
                {
                    ++count;
                }
                else
                {
                    try
                    {
                        int number = Convert.ToInt32( replace );
                        count = System.Math.Max( count, number + 1 );
                    }
                    catch( FormatException e )
                    {
                    }
                }
            }

            if( count > 0 )
            {
                defualtName += count.ToString();
            }

            return defualtName;
        }
    }
}
