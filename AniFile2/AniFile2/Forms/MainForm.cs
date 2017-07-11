using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using System.IO;

namespace AniFile2
{
    public partial class MainForm : Form
    {
        private AniFileNode m_rootNode = new AniFileNode( "전체" );

        struct DropItem
        {
            public AniFileNode node;
            public Dictionary<string, string> items;
        }

        // 자료구조 정의
        // 1. 트리구조
        // 2. 제목+화수로 구성
        // 3. 트리
        public MainForm()
        {
            InitializeComponent();
            treeView1.Nodes.Add( m_rootNode );
        }

        private void treeView1_DragOver( object sender, DragEventArgs e )
        {
            Point point = treeView1.PointToClient( new Point( e.X, e.Y ) );

            treeView1.SelectedNode = treeView1.GetNodeAt( point );
            e.Effect = DragDropEffects.Move;
        }

        private void treeView1_ItemDrag( object sender, ItemDragEventArgs e )
        {
            DoDragDrop( e.Item, DragDropEffects.Move );
        }

        private void treeView1_DragEnter( object sender, DragEventArgs e )
        {
            e.Effect = DragDropEffects.Move;
        }

        private void treeView1_DragDrop( object sender, DragEventArgs e )
        {
            object listItem = e.Data.GetData( "listItem" );
            if( listItem != null )
            {
                DropItem dropItem = ( DropItem )listItem;

                AniFileNode selectedNode = treeView1.SelectedNode as AniFileNode;

                foreach( KeyValuePair<string,string> item in dropItem.items )
                {
                    selectedNode.Files.Add( item.Key, Convert.ToUInt32( item.Value ) );
                    dropItem.node.Files.Remove( item.Key );
                }

                UpdateListView( selectedNode );
            }
            else
            {
                AniFileNode dropNode = e.Data.GetData( typeof( AniFileNode ) ) as AniFileNode;
                if( dropNode != null )
                {
                    AniFileNode selectedNode = treeView1.SelectedNode as AniFileNode;
                    AniFileNode parentNode = dropNode.Parent as AniFileNode;

                    if( dropNode != selectedNode
                        && parentNode != null )
                    {
                        parentNode.Nodes.Remove( dropNode );
                        selectedNode.Nodes.Add( dropNode );
                    }
                }
            }
        }

        private void listView1_ItemDrag( object sender, ItemDragEventArgs e )
        {
            DoDragDrop( e.Item, DragDropEffects.Move );
        }


        private void UpdateListView( AniFileNode folder )
        {
            // listView에 Viewing 한다
            listView1.Items.Clear();
            listView1.Groups.Clear();
            ListViewGroup group = listView1.Groups.Add( folder.Text, folder.FullPath );
            foreach( KeyValuePair<string, uint> file in folder.Files )
            {
                string[] itmes = { file.Key, file.Value.ToString() };
                listView1.Items.Add( new ListViewItem( itmes, group ) );
            }
        }

        private void NewFolder(string name)
        {
            AniFileNode selectedNode = treeView1.SelectedNode as AniFileNode;
            if( name.Length == 0 )
            {
                name = selectedNode.GetNewFolderName();
            }
            else
            {
                foreach( AniFileNode node in selectedNode.Nodes )
                {
                    if( node.Text == name )
                    {
                        MessageBox.Show( "같은 이름이 이미 존재합니다.", "도움말", MessageBoxButtons.OK, MessageBoxIcon.Information );
                        return;
                    }
                }
            }

            if( selectedNode != null )
            {
                treeView1.SelectedNode.Nodes.Add( new AniFileNode( name ) );
            }
        }

        private void NewFile( string name )
        {
            AniFileNode folder = treeView1.SelectedNode as AniFileNode;
            if( folder == null )
            {
                return;
            }

            if( folder.Files.ContainsKey( name ) )
            {
                MessageBox.Show( "같은 이름이 이미 존재합니다.", "도움말", MessageBoxButtons.OK, MessageBoxIcon.Information );
                return;
            }

            if( name.Length == 0 )
            {
                name = folder.GetNewFileName();
            }
            
            folder.Files.Add( name, 1 );
            UpdateListView( folder );
        }

        private void EpsiodeCount()
        {
            AniFileNode selectedNode = treeView1.SelectedNode as AniFileNode;
            if( selectedNode != null )
            {
                foreach( ListViewItem item in listView1.SelectedItems )
                {
                    ++selectedNode.Files[ item.Text ];
                    item.SubItems[ 1 ].Text = selectedNode.Files[ item.Text ].ToString();
                }
            }
        }

        private void treeView1_AfterSelect( object sender, TreeViewEventArgs e )
        {
            AniFileNode selectedNode = treeView1.SelectedNode as AniFileNode;
            if( selectedNode != null )
            {
                UpdateListView( selectedNode );
            }   
        }

        private void 새파일ToolStripMenuItem2_Click( object sender, EventArgs e )
        {
            NewFile( "" );
        }

        private void 새폴더ToolStripMenuItem1_Click( object sender, EventArgs e )
        {
            NewFolder( "" );
        }

        private void 삭제ToolStripMenuItem_Click( object sender, EventArgs e )
        {
            if( treeView1.SelectedNode != null )
            {
                treeView1.SelectedNode.Remove();
            }
        }

        private void 삭제ToolStripMenuItem1_Click( object sender, EventArgs e )
        {
            AniFileNode selectedNode = treeView1.SelectedNode as AniFileNode;
            if( selectedNode != null )
            {
                foreach( ListViewItem item in listView1.SelectedItems )
                {
                    selectedNode.Files.Remove( item.Text );
                }

                UpdateListView( selectedNode );
            }
        }

        private void 이름바꾸기ToolStripMenuItem1_Click( object sender, EventArgs e )
        {
            treeView1.SelectedNode.BeginEdit();
        }

        private void treeView1_KeyDown( object sender, KeyEventArgs e )
        {
            if( e.KeyCode == Keys.F2 )
            {
                treeView1.SelectedNode.BeginEdit();
            }
        }

        private void 이름바꾸기ToolStripMenuItem_Click( object sender, EventArgs e )
        {
            if( listView1.SelectedItems.Count > 0 )
            {
                listView1.SelectedItems[ 0 ].BeginEdit();
            }
        }

        private void listView1_KeyDown( object sender, KeyEventArgs e )
        {
            if( e.KeyCode == Keys.F2
                && listView1.SelectedItems.Count > 0 )
            {
                listView1.SelectedItems[ 0 ].BeginEdit();
            }
        }

        private void toolStripButton1_Click( object sender, EventArgs e )
        {
            EpsiodeCount();
        }

        private void 화수올리기ToolStripMenuItem_Click( object sender, EventArgs e )
        {
            EpsiodeCount();
        }

        private void listView1_DoubleClick( object sender, EventArgs e )
        {
            AniFileNode selectedNode = treeView1.SelectedNode as AniFileNode;

            string name = listView1.SelectedItems[ 0 ].Text;
            uint epsoideCount = selectedNode.Files[ name ];

            EditableForm form = new EditableForm( name, epsoideCount );
            if( form.ShowDialog() == DialogResult.OK )
            {
                selectedNode.Files.Remove( name );
                selectedNode.Files.Add( form.textBox1.Text, Convert.ToUInt32( form.textBox2.Text ) );
                UpdateListView( selectedNode );
            }
        }

        private void listView1_AfterLabelEdit( object sender, LabelEditEventArgs e )
        {
            AniFileNode selectedNode = treeView1.SelectedNode as AniFileNode;
            
            uint value = selectedNode.Files[ listView1.FocusedItem.Text ];
            selectedNode.Files.Add( e.Label, value );

            selectedNode.Files.Remove( listView1.FocusedItem.Text );
        }

        private void 열기ToolStripMenuItem_Click( object sender, EventArgs e )
        {
            if( openFileDialog1.ShowDialog() == DialogResult.OK )
            {
                FileManager fileManager = new FileManager( openFileDialog1.FileName );
                fileManager.Load( treeView1.Nodes );
            }            
        }

        private void listView1_DragEnter( object sender, DragEventArgs e )
        {
            e.Effect = DragDropEffects.Move;

            DropItem dropItem = new DropItem();

            dropItem.node = treeView1.SelectedNode as AniFileNode;
            dropItem.items = new Dictionary<string, string>();
                        
            foreach( ListViewItem item in listView1.SelectedItems )
            {
                dropItem.items[ item.Text ] = item.SubItems[ 1 ].Text;
            }

            e.Data.SetData( "listItem", dropItem );
        }

        private void 저장ToolStripMenuItem_Click( object sender, EventArgs e )
        {
            if( saveFileDialog1.ShowDialog() == DialogResult.OK )
            {
                FileManager fileManager = new FileManager( saveFileDialog1.FileName );
                fileManager.Save( treeView1.Nodes );
            }
        }

        private void Find( string keyword )
        {
            // CompareCount를 기준으로 sort해서 표시해야된다.
            // CompareCount == keyword.Lenght 일 경우, 우선순위가 젤 높다(가장 상위에 표시해줘야함)
            foreach( AniFileNode node in treeView1.Nodes )
            {
                foreach( string file in node.Files.Keys )
                {
                    int compareCount = 0;
                    foreach( char word1 in keyword )
                    {
                        foreach( char word2 in file )
                        {
                            if( word1 == word2 )
                            {
                                ++compareCount;
                                break;
                            }
                        }
                    }
                }
            }
        }

        private void toolStripComboBox1_KeyDown( object sender, KeyEventArgs e )
        {
            if( e.KeyCode == Keys.Enter )
            {
                Find( toolStripComboBox1.Text );
            }
        }
    }
}
