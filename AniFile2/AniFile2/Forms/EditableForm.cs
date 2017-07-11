using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace AniFile2
{
    public partial class EditableForm : Form
    {
        public EditableForm( string name, uint epsoideCount )
        {
            InitializeComponent();
            textBox1.Text = name;
            textBox2.Text = epsoideCount.ToString();
        }

        private void textBox2_KeyPress( object sender, KeyPressEventArgs e )
        {
            if( !( char.IsDigit( e.KeyChar ) || e.KeyChar == Convert.ToChar( Keys.Back ) ) )
            {
                e.Handled = true;
            }
        }
    }
}
