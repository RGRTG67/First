using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp1
{
    public partial class Form2 : Form
    {
        public Form2()
        {
            InitializeComponent();
            button1.Enabled = false;
        }
        Random r = new Random();
        int x, y;
        int score = 0;
        int timeLeft=60;
        private void pictureBox1_Click(object sender, EventArgs e)
        {
            score++;
            label2.Text = score.ToString() + " 分";
            y = r.Next(70, 950);
            x = r.Next(75, 1850);
            Point p1 = new Point(x, y);
            pictureBox1.Location = p1;
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            if (timeLeft > 0)
            {
                label3.Text = timeLeft + " 秒";
                timeLeft = timeLeft - 1;
            }
            else
            {
                timer1.Stop();
                MessageBox.Show("你的分數是:"+score+"分");
                button2.Enabled = true;
                label2.Text = "0 分";
                label3.Text = "0 秒";
                button1.Enabled = false;
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            pictureBox1.Visible = true;
            timer1.Enabled = true;
            timeLeft = 60;
            button2.Enabled = false;
            button1.Enabled = true;
            label2.Text = "0 分";
        }

        private void button3_Click(object sender, EventArgs e)
        {
            timer1.Enabled = false;
            DialogResult r;
            r = MessageBox.Show("你確定要結束遊戲", "結束", MessageBoxButtons.YesNo,MessageBoxIcon.Information);
            if(r == DialogResult.Yes)
            {
                this.Close();
            }
            else
            {
                timer1.Enabled = true;
            }

        }

        private void button1_Click(object sender, EventArgs e)
        {
            y = r.Next(70, 950);
            x = r.Next(75, 1850);
            Point p1 = new Point(x, y);
            pictureBox1.Location = p1;
            label2.Text = "0 分";
            label3.Text = "0 秒";
            timeLeft = 60;
            timer1.Enabled = false;
            button2.Enabled = true;
            button1.Enabled = false;
        }

      
    }
}
