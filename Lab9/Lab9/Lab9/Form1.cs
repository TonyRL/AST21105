using System;
using System.Windows.Forms;
using MultiplicationCode;

namespace Lab9
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void calculateButton_Click(object sender, EventArgs e)
        {
            // Create an object of type MathsOperations defined in C++
            var mOper = new MathsOperations();
            // Obtain the value in textbox "valueX" and
            // change from string to int
            var x = int.Parse(valueX.Text);
            // Obtain the value in textbox "valueY" and
            // change from string to int
            var y = int.Parse(valueY.Text);
            // Call the member function "multiply" and obtain the result
            var result = mOper.multiply(x, y);
            // Show the result by a popped up window
            MessageBox.Show("The result is: " + result);
        }
    }
}