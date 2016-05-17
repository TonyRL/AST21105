namespace Lab9
{
    partial class Form1
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
            calculateButton = new System.Windows.Forms.Button();
            xLabel = new System.Windows.Forms.Label();
            yLabel = new System.Windows.Forms.Label();
            valueX = new System.Windows.Forms.TextBox();
            valueY = new System.Windows.Forms.TextBox();
            SuspendLayout();
            // 
            // calculateButton
            // 
            calculateButton.Location = new System.Drawing.Point(94, 156);
            calculateButton.Name = "calculateButton";
            calculateButton.Size = new System.Drawing.Size(75, 23);
            calculateButton.TabIndex = 0;
            calculateButton.Text = "Calculate";
            calculateButton.UseVisualStyleBackColor = true;
            calculateButton.Click += new System.EventHandler(calculateButton_Click);
            // 
            // xLabel
            // 
            xLabel.AutoSize = true;
            xLabel.Location = new System.Drawing.Point(44, 55);
            xLabel.Name = "xLabel";
            xLabel.Size = new System.Drawing.Size(48, 14);
            xLabel.TabIndex = 1;
            xLabel.Text = "Value X";
            // 
            // yLabel
            // 
            yLabel.AutoSize = true;
            yLabel.Location = new System.Drawing.Point(47, 104);
            yLabel.Name = "yLabel";
            yLabel.Size = new System.Drawing.Size(48, 14);
            yLabel.TabIndex = 2;
            yLabel.Text = "Value X";
            // 
            // valueX
            // 
            valueX.Location = new System.Drawing.Point(149, 52);
            valueX.Name = "valueX";
            valueX.Size = new System.Drawing.Size(100, 22);
            valueX.TabIndex = 3;
            // 
            // valueY
            // 
            valueY.Location = new System.Drawing.Point(149, 104);
            valueY.Name = "valueY";
            valueY.Size = new System.Drawing.Size(100, 22);
            valueY.TabIndex = 4;
            // 
            // Form1
            // 
            AutoScaleDimensions = new System.Drawing.SizeF(7F, 14F);
            AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            ClientSize = new System.Drawing.Size(284, 262);
            Controls.Add(valueY);
            Controls.Add(valueX);
            Controls.Add(yLabel);
            Controls.Add(xLabel);
            Controls.Add(calculateButton);
            Name = "Form1";
            Text = "Form1";
            ResumeLayout(false);
            PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button calculateButton;
        private System.Windows.Forms.Label xLabel;
        private System.Windows.Forms.Label yLabel;
        private System.Windows.Forms.TextBox valueX;
        private System.Windows.Forms.TextBox valueY;
    }
}

