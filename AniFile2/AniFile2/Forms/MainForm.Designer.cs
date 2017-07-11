namespace AniFile2
{
    partial class MainForm
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            System.Windows.Forms.ListViewItem listViewItem9 = new System.Windows.Forms.ListViewItem( "bnnhj" );
            System.Windows.Forms.ListViewItem listViewItem10 = new System.Windows.Forms.ListViewItem( "dfdfhh" );
            System.Windows.Forms.ListViewItem listViewItem11 = new System.Windows.Forms.ListViewItem( "fd" );
            System.Windows.Forms.ListViewItem listViewItem12 = new System.Windows.Forms.ListViewItem( "rtrey" );
            System.Windows.Forms.ListViewItem listViewItem13 = new System.Windows.Forms.ListViewItem( "xcvcv" );
            System.Windows.Forms.ListViewItem listViewItem14 = new System.Windows.Forms.ListViewItem( "yutyrty" );
            System.Windows.Forms.ListViewItem listViewItem15 = new System.Windows.Forms.ListViewItem( "ㅇㄹㄴㅇㄹ" );
            System.Windows.Forms.ListViewItem listViewItem16 = new System.Windows.Forms.ListViewItem( new string[] {
            "ㅊㄴㅇㅀㄴㅇ",
            "dvsv",
            ""}, -1 );
            this.listView1 = new System.Windows.Forms.ListView();
            this.columnHeader1 = ( ( System.Windows.Forms.ColumnHeader )( new System.Windows.Forms.ColumnHeader() ) );
            this.columnHeader2 = ( ( System.Windows.Forms.ColumnHeader )( new System.Windows.Forms.ColumnHeader() ) );
            this.contextMenuStrip2 = new System.Windows.Forms.ContextMenuStrip( this.components );
            this.화수올리기ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.새파일ToolStripMenuItem2 = new System.Windows.Forms.ToolStripMenuItem();
            this.이름바꾸기ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.삭제ToolStripMenuItem1 = new System.Windows.Forms.ToolStripMenuItem();
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.파일ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.열기ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.저장ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator2 = new System.Windows.Forms.ToolStripSeparator();
            this.닫기ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.편집ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.개발자에게ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.건의ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.버그ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.그냥메세지ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStrip1 = new System.Windows.Forms.ToolStrip();
            this.toolStripButton1 = new System.Windows.Forms.ToolStripButton();
            this.toolStripSeparator5 = new System.Windows.Forms.ToolStripSeparator();
            this.toolStripComboBox1 = new System.Windows.Forms.ToolStripComboBox();
            this.toolStripButton2 = new System.Windows.Forms.ToolStripButton();
            this.toolStripSeparator4 = new System.Windows.Forms.ToolStripSeparator();
            this.toolStripButton4 = new System.Windows.Forms.ToolStripButton();
            this.splitContainer1 = new System.Windows.Forms.SplitContainer();
            this.treeView1 = new System.Windows.Forms.TreeView();
            this.contextMenuStrip1 = new System.Windows.Forms.ContextMenuStrip( this.components );
            this.새폴더ToolStripMenuItem1 = new System.Windows.Forms.ToolStripMenuItem();
            this.이름바꾸기ToolStripMenuItem1 = new System.Windows.Forms.ToolStripMenuItem();
            this.삭제ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.openFileDialog1 = new System.Windows.Forms.OpenFileDialog();
            this.saveFileDialog1 = new System.Windows.Forms.SaveFileDialog();
            this.contextMenuStrip2.SuspendLayout();
            this.menuStrip1.SuspendLayout();
            this.toolStrip1.SuspendLayout();
            this.splitContainer1.Panel1.SuspendLayout();
            this.splitContainer1.Panel2.SuspendLayout();
            this.splitContainer1.SuspendLayout();
            this.contextMenuStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // listView1
            // 
            this.listView1.Activation = System.Windows.Forms.ItemActivation.OneClick;
            this.listView1.AllowDrop = true;
            this.listView1.Columns.AddRange( new System.Windows.Forms.ColumnHeader[] {
            this.columnHeader1,
            this.columnHeader2} );
            this.listView1.ContextMenuStrip = this.contextMenuStrip2;
            this.listView1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.listView1.FullRowSelect = true;
            this.listView1.Items.AddRange( new System.Windows.Forms.ListViewItem[] {
            listViewItem9,
            listViewItem10,
            listViewItem11,
            listViewItem12,
            listViewItem13,
            listViewItem14,
            listViewItem15,
            listViewItem16} );
            this.listView1.LabelEdit = true;
            this.listView1.Location = new System.Drawing.Point( 0, 0 );
            this.listView1.Name = "listView1";
            this.listView1.Size = new System.Drawing.Size( 442, 519 );
            this.listView1.Sorting = System.Windows.Forms.SortOrder.Ascending;
            this.listView1.TabIndex = 0;
            this.listView1.UseCompatibleStateImageBehavior = false;
            this.listView1.View = System.Windows.Forms.View.Details;
            this.listView1.AfterLabelEdit += new System.Windows.Forms.LabelEditEventHandler( this.listView1_AfterLabelEdit );
            this.listView1.ItemDrag += new System.Windows.Forms.ItemDragEventHandler( this.listView1_ItemDrag );
            this.listView1.DragEnter += new System.Windows.Forms.DragEventHandler( this.listView1_DragEnter );
            this.listView1.DoubleClick += new System.EventHandler( this.listView1_DoubleClick );
            this.listView1.KeyDown += new System.Windows.Forms.KeyEventHandler( this.listView1_KeyDown );
            // 
            // columnHeader1
            // 
            this.columnHeader1.Text = "제목";
            this.columnHeader1.Width = 200;
            // 
            // columnHeader2
            // 
            this.columnHeader2.Text = "화수";
            // 
            // contextMenuStrip2
            // 
            this.contextMenuStrip2.Items.AddRange( new System.Windows.Forms.ToolStripItem[] {
            this.화수올리기ToolStripMenuItem,
            this.새파일ToolStripMenuItem2,
            this.이름바꾸기ToolStripMenuItem,
            this.삭제ToolStripMenuItem1} );
            this.contextMenuStrip2.Name = "contextMenuStrip2";
            this.contextMenuStrip2.Size = new System.Drawing.Size( 139, 92 );
            // 
            // 화수올리기ToolStripMenuItem
            // 
            this.화수올리기ToolStripMenuItem.Image = global::AniFile2.Properties.Resources.arrow_large_up;
            this.화수올리기ToolStripMenuItem.Name = "화수올리기ToolStripMenuItem";
            this.화수올리기ToolStripMenuItem.Size = new System.Drawing.Size( 138, 22 );
            this.화수올리기ToolStripMenuItem.Text = "화수 올리기";
            this.화수올리기ToolStripMenuItem.Click += new System.EventHandler( this.화수올리기ToolStripMenuItem_Click );
            // 
            // 새파일ToolStripMenuItem2
            // 
            this.새파일ToolStripMenuItem2.Image = global::AniFile2.Properties.Resources.document_a4_new;
            this.새파일ToolStripMenuItem2.Name = "새파일ToolStripMenuItem2";
            this.새파일ToolStripMenuItem2.Size = new System.Drawing.Size( 138, 22 );
            this.새파일ToolStripMenuItem2.Text = "새 파일";
            this.새파일ToolStripMenuItem2.Click += new System.EventHandler( this.새파일ToolStripMenuItem2_Click );
            // 
            // 이름바꾸기ToolStripMenuItem
            // 
            this.이름바꾸기ToolStripMenuItem.Name = "이름바꾸기ToolStripMenuItem";
            this.이름바꾸기ToolStripMenuItem.Size = new System.Drawing.Size( 138, 22 );
            this.이름바꾸기ToolStripMenuItem.Text = "이름 바꾸기";
            this.이름바꾸기ToolStripMenuItem.Click += new System.EventHandler( this.이름바꾸기ToolStripMenuItem_Click );
            // 
            // 삭제ToolStripMenuItem1
            // 
            this.삭제ToolStripMenuItem1.Image = global::AniFile2.Properties.Resources.action_delete;
            this.삭제ToolStripMenuItem1.Name = "삭제ToolStripMenuItem1";
            this.삭제ToolStripMenuItem1.Size = new System.Drawing.Size( 138, 22 );
            this.삭제ToolStripMenuItem1.Text = "삭제";
            this.삭제ToolStripMenuItem1.Click += new System.EventHandler( this.삭제ToolStripMenuItem1_Click );
            // 
            // menuStrip1
            // 
            this.menuStrip1.Items.AddRange( new System.Windows.Forms.ToolStripItem[] {
            this.파일ToolStripMenuItem,
            this.편집ToolStripMenuItem,
            this.개발자에게ToolStripMenuItem} );
            this.menuStrip1.Location = new System.Drawing.Point( 0, 0 );
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size( 668, 24 );
            this.menuStrip1.TabIndex = 1;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // 파일ToolStripMenuItem
            // 
            this.파일ToolStripMenuItem.DropDownItems.AddRange( new System.Windows.Forms.ToolStripItem[] {
            this.열기ToolStripMenuItem,
            this.저장ToolStripMenuItem,
            this.toolStripSeparator2,
            this.닫기ToolStripMenuItem} );
            this.파일ToolStripMenuItem.Name = "파일ToolStripMenuItem";
            this.파일ToolStripMenuItem.Size = new System.Drawing.Size( 43, 20 );
            this.파일ToolStripMenuItem.Text = "파일";
            // 
            // 열기ToolStripMenuItem
            // 
            this.열기ToolStripMenuItem.Name = "열기ToolStripMenuItem";
            this.열기ToolStripMenuItem.Size = new System.Drawing.Size( 98, 22 );
            this.열기ToolStripMenuItem.Text = "열기";
            this.열기ToolStripMenuItem.Click += new System.EventHandler( this.열기ToolStripMenuItem_Click );
            // 
            // 저장ToolStripMenuItem
            // 
            this.저장ToolStripMenuItem.Image = global::AniFile2.Properties.Resources.save;
            this.저장ToolStripMenuItem.Name = "저장ToolStripMenuItem";
            this.저장ToolStripMenuItem.Size = new System.Drawing.Size( 98, 22 );
            this.저장ToolStripMenuItem.Text = "저장";
            this.저장ToolStripMenuItem.Click += new System.EventHandler( this.저장ToolStripMenuItem_Click );
            // 
            // toolStripSeparator2
            // 
            this.toolStripSeparator2.Name = "toolStripSeparator2";
            this.toolStripSeparator2.Size = new System.Drawing.Size( 95, 6 );
            // 
            // 닫기ToolStripMenuItem
            // 
            this.닫기ToolStripMenuItem.Name = "닫기ToolStripMenuItem";
            this.닫기ToolStripMenuItem.Size = new System.Drawing.Size( 98, 22 );
            this.닫기ToolStripMenuItem.Text = "닫기";
            // 
            // 편집ToolStripMenuItem
            // 
            this.편집ToolStripMenuItem.Name = "편집ToolStripMenuItem";
            this.편집ToolStripMenuItem.Size = new System.Drawing.Size( 43, 20 );
            this.편집ToolStripMenuItem.Text = "편집";
            // 
            // 개발자에게ToolStripMenuItem
            // 
            this.개발자에게ToolStripMenuItem.DropDownItems.AddRange( new System.Windows.Forms.ToolStripItem[] {
            this.건의ToolStripMenuItem,
            this.버그ToolStripMenuItem,
            this.그냥메세지ToolStripMenuItem} );
            this.개발자에게ToolStripMenuItem.Name = "개발자에게ToolStripMenuItem";
            this.개발자에게ToolStripMenuItem.Size = new System.Drawing.Size( 79, 20 );
            this.개발자에게ToolStripMenuItem.Text = "개발자에게";
            // 
            // 건의ToolStripMenuItem
            // 
            this.건의ToolStripMenuItem.Name = "건의ToolStripMenuItem";
            this.건의ToolStripMenuItem.Size = new System.Drawing.Size( 138, 22 );
            this.건의ToolStripMenuItem.Text = "건의";
            // 
            // 버그ToolStripMenuItem
            // 
            this.버그ToolStripMenuItem.Name = "버그ToolStripMenuItem";
            this.버그ToolStripMenuItem.Size = new System.Drawing.Size( 138, 22 );
            this.버그ToolStripMenuItem.Text = "버그 신고";
            // 
            // 그냥메세지ToolStripMenuItem
            // 
            this.그냥메세지ToolStripMenuItem.Name = "그냥메세지ToolStripMenuItem";
            this.그냥메세지ToolStripMenuItem.Size = new System.Drawing.Size( 138, 22 );
            this.그냥메세지ToolStripMenuItem.Text = "그냥 메세지";
            // 
            // toolStrip1
            // 
            this.toolStrip1.Items.AddRange( new System.Windows.Forms.ToolStripItem[] {
            this.toolStripButton1,
            this.toolStripSeparator5,
            this.toolStripComboBox1,
            this.toolStripButton2,
            this.toolStripSeparator4,
            this.toolStripButton4} );
            this.toolStrip1.Location = new System.Drawing.Point( 0, 24 );
            this.toolStrip1.Name = "toolStrip1";
            this.toolStrip1.Size = new System.Drawing.Size( 668, 25 );
            this.toolStrip1.TabIndex = 2;
            this.toolStrip1.Text = "toolStrip1";
            // 
            // toolStripButton1
            // 
            this.toolStripButton1.Image = global::AniFile2.Properties.Resources.arrow_large_up;
            this.toolStripButton1.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.toolStripButton1.Name = "toolStripButton1";
            this.toolStripButton1.Size = new System.Drawing.Size( 91, 22 );
            this.toolStripButton1.Text = "화수 올리기";
            this.toolStripButton1.Click += new System.EventHandler( this.toolStripButton1_Click );
            // 
            // toolStripSeparator5
            // 
            this.toolStripSeparator5.Name = "toolStripSeparator5";
            this.toolStripSeparator5.Size = new System.Drawing.Size( 6, 25 );
            // 
            // toolStripComboBox1
            // 
            this.toolStripComboBox1.Name = "toolStripComboBox1";
            this.toolStripComboBox1.Size = new System.Drawing.Size( 121, 25 );
            this.toolStripComboBox1.KeyDown += new System.Windows.Forms.KeyEventHandler( this.toolStripComboBox1_KeyDown );
            // 
            // toolStripButton2
            // 
            this.toolStripButton2.Image = global::AniFile2.Properties.Resources.search_button_green_16;
            this.toolStripButton2.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.toolStripButton2.Name = "toolStripButton2";
            this.toolStripButton2.Size = new System.Drawing.Size( 51, 22 );
            this.toolStripButton2.Text = "검색";
            // 
            // toolStripSeparator4
            // 
            this.toolStripSeparator4.Name = "toolStripSeparator4";
            this.toolStripSeparator4.Size = new System.Drawing.Size( 6, 25 );
            // 
            // toolStripButton4
            // 
            this.toolStripButton4.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.toolStripButton4.Name = "toolStripButton4";
            this.toolStripButton4.Size = new System.Drawing.Size( 69, 22 );
            this.toolStripButton4.Text = "종료&&저장";
            // 
            // splitContainer1
            // 
            this.splitContainer1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.splitContainer1.Location = new System.Drawing.Point( 0, 49 );
            this.splitContainer1.Name = "splitContainer1";
            // 
            // splitContainer1.Panel1
            // 
            this.splitContainer1.Panel1.Controls.Add( this.treeView1 );
            // 
            // splitContainer1.Panel2
            // 
            this.splitContainer1.Panel2.Controls.Add( this.listView1 );
            this.splitContainer1.Size = new System.Drawing.Size( 668, 519 );
            this.splitContainer1.SplitterDistance = 222;
            this.splitContainer1.TabIndex = 3;
            // 
            // treeView1
            // 
            this.treeView1.AllowDrop = true;
            this.treeView1.ContextMenuStrip = this.contextMenuStrip1;
            this.treeView1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.treeView1.HideSelection = false;
            this.treeView1.HotTracking = true;
            this.treeView1.LabelEdit = true;
            this.treeView1.Location = new System.Drawing.Point( 0, 0 );
            this.treeView1.Name = "treeView1";
            this.treeView1.Size = new System.Drawing.Size( 222, 519 );
            this.treeView1.TabIndex = 0;
            this.treeView1.ItemDrag += new System.Windows.Forms.ItemDragEventHandler( this.treeView1_ItemDrag );
            this.treeView1.AfterSelect += new System.Windows.Forms.TreeViewEventHandler( this.treeView1_AfterSelect );
            this.treeView1.DragDrop += new System.Windows.Forms.DragEventHandler( this.treeView1_DragDrop );
            this.treeView1.DragEnter += new System.Windows.Forms.DragEventHandler( this.treeView1_DragEnter );
            this.treeView1.DragOver += new System.Windows.Forms.DragEventHandler( this.treeView1_DragOver );
            this.treeView1.KeyDown += new System.Windows.Forms.KeyEventHandler( this.treeView1_KeyDown );
            // 
            // contextMenuStrip1
            // 
            this.contextMenuStrip1.Items.AddRange( new System.Windows.Forms.ToolStripItem[] {
            this.새폴더ToolStripMenuItem1,
            this.이름바꾸기ToolStripMenuItem1,
            this.삭제ToolStripMenuItem} );
            this.contextMenuStrip1.Name = "contextMenuStrip1";
            this.contextMenuStrip1.Size = new System.Drawing.Size( 139, 70 );
            // 
            // 새폴더ToolStripMenuItem1
            // 
            this.새폴더ToolStripMenuItem1.Image = global::AniFile2.Properties.Resources.folder_new;
            this.새폴더ToolStripMenuItem1.Name = "새폴더ToolStripMenuItem1";
            this.새폴더ToolStripMenuItem1.Size = new System.Drawing.Size( 138, 22 );
            this.새폴더ToolStripMenuItem1.Text = "새 폴더";
            this.새폴더ToolStripMenuItem1.Click += new System.EventHandler( this.새폴더ToolStripMenuItem1_Click );
            // 
            // 이름바꾸기ToolStripMenuItem1
            // 
            this.이름바꾸기ToolStripMenuItem1.Name = "이름바꾸기ToolStripMenuItem1";
            this.이름바꾸기ToolStripMenuItem1.Size = new System.Drawing.Size( 138, 22 );
            this.이름바꾸기ToolStripMenuItem1.Text = "이름 바꾸기";
            this.이름바꾸기ToolStripMenuItem1.Click += new System.EventHandler( this.이름바꾸기ToolStripMenuItem1_Click );
            // 
            // 삭제ToolStripMenuItem
            // 
            this.삭제ToolStripMenuItem.Image = global::AniFile2.Properties.Resources.action_delete;
            this.삭제ToolStripMenuItem.Name = "삭제ToolStripMenuItem";
            this.삭제ToolStripMenuItem.Size = new System.Drawing.Size( 138, 22 );
            this.삭제ToolStripMenuItem.Text = "삭제";
            this.삭제ToolStripMenuItem.Click += new System.EventHandler( this.삭제ToolStripMenuItem_Click );
            // 
            // openFileDialog1
            // 
            this.openFileDialog1.Filter = "XML(*.xml)|*.xml|Sav(*.sav)|*.sav|모든 파일(*.*)|*.*";
            // 
            // saveFileDialog1
            // 
            this.saveFileDialog1.Filter = "XML(*.xml)|*.xml";
            // 
            // MainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF( 7F, 12F );
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size( 668, 568 );
            this.Controls.Add( this.splitContainer1 );
            this.Controls.Add( this.toolStrip1 );
            this.Controls.Add( this.menuStrip1 );
            this.MainMenuStrip = this.menuStrip1;
            this.Name = "MainForm";
            this.Text = "AniFile.Net";
            this.contextMenuStrip2.ResumeLayout( false );
            this.menuStrip1.ResumeLayout( false );
            this.menuStrip1.PerformLayout();
            this.toolStrip1.ResumeLayout( false );
            this.toolStrip1.PerformLayout();
            this.splitContainer1.Panel1.ResumeLayout( false );
            this.splitContainer1.Panel2.ResumeLayout( false );
            this.splitContainer1.ResumeLayout( false );
            this.contextMenuStrip1.ResumeLayout( false );
            this.ResumeLayout( false );
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ListView listView1;
        private System.Windows.Forms.ColumnHeader columnHeader1;
        private System.Windows.Forms.ColumnHeader columnHeader2;
        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem 파일ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 열기ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 저장ToolStripMenuItem;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator2;
        private System.Windows.Forms.ToolStripMenuItem 닫기ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 편집ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 개발자에게ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 건의ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 버그ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 그냥메세지ToolStripMenuItem;
        private System.Windows.Forms.ToolStrip toolStrip1;
        private System.Windows.Forms.SplitContainer splitContainer1;
        private System.Windows.Forms.TreeView treeView1;
        private System.Windows.Forms.ToolStripButton toolStripButton1;
        private System.Windows.Forms.ToolStripButton toolStripButton2;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator4;
        private System.Windows.Forms.ToolStripButton toolStripButton4;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator5;
        private System.Windows.Forms.ToolStripComboBox toolStripComboBox1;
        private System.Windows.Forms.ContextMenuStrip contextMenuStrip1;
        private System.Windows.Forms.ToolStripMenuItem 새폴더ToolStripMenuItem1;
        private System.Windows.Forms.ToolStripMenuItem 삭제ToolStripMenuItem;
        private System.Windows.Forms.ContextMenuStrip contextMenuStrip2;
        private System.Windows.Forms.ToolStripMenuItem 새파일ToolStripMenuItem2;
        private System.Windows.Forms.ToolStripMenuItem 삭제ToolStripMenuItem1;
        private System.Windows.Forms.ToolStripMenuItem 이름바꾸기ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 이름바꾸기ToolStripMenuItem1;
        private System.Windows.Forms.ToolStripMenuItem 화수올리기ToolStripMenuItem;
        private System.Windows.Forms.OpenFileDialog openFileDialog1;
        private System.Windows.Forms.SaveFileDialog saveFileDialog1;
    }
}

