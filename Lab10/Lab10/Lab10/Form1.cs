using System;
using System.Drawing;
using System.Windows.Forms;

namespace Lab10
{
    public partial class Form1 : Form
    {
        private readonly MyPictureBox[] pb = new MyPictureBox[13];
        private readonly TextBox tb = new TextBox();
        private int noCard;


        public Form1()
        {
            InitializeComponent();
            SuspendLayout();
            Text = "Lab10 - More on GUI Programming using C#";
            ClientSize = new Size(395, 100);
            for (var i = 0; i < 13; i++)
            {
                pb[i] = new MyPictureBox();
                pb[i].Image = Image.FromFile("image1" + (i + 1) + ".jpg");
                pb[i].Location = new Point(10 + i * 26, 35);
                pb[i].Size = new Size(26, 36);
                pb[i].Click += pictureBox_MouseDown;
                Controls.Add(pb[i]);
            }
            tb.Location = new Point(360, 39);
            tb.Width = 20;
            tb.TextAlign = HorizontalAlignment.Center;
            tb.Text = noCard.ToString();
            Controls.Add(tb);
            ResumeLayout();
        }


        private void pictureBox_MouseDown(object sender, EventArgs e)
        {
            if (!((MyPictureBox) sender).isSelected())
            {
                ((MyPictureBox) sender).Location = new Point(((PictureBox) sender).Location.X,
                    ((PictureBox) sender).Location.Y - 10);
                ((MyPictureBox) sender).setSelected(true);
                noCard++;
            }
            else
            {
                ((MyPictureBox) sender).Location = new Point(((PictureBox) sender).Location.X,
                    ((PictureBox) sender).Location.Y + 10);
                ((MyPictureBox) sender).setSelected(false);
                noCard--;
            }
            tb.Text = noCard.ToString();
        }


        public class MyPictureBox : PictureBox
        {
            private bool selected;

            public bool isSelected()
            {
                return selected;
            }

            public void setSelected(bool s)
            {
                selected = s;
            }
        }
    }
}