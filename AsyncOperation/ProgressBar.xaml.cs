using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Shapes;

namespace AsyncOperation
{
    /// <summary>
    /// Interaction logic for ProgressBar.xaml
    /// </summary>
    public partial class ProgressBar : Window
    {
        public ProgressBar()
        {
            InitializeComponent();
        }

        private void BtnClick_Click(object sender, RoutedEventArgs e)
        {
            Thread progressThread = new Thread(PerformTask);
            progressThread.Start();
        }

        private void PerformTask()
        {
            for (int i = 0; i < 20; i++)
            {
                Thread.Sleep(1000);
                SetProgress(i);
            }
        }

        private void SetProgress(int i)
        {
            if(!Dispatcher.CheckAccess())
            {
                Dispatcher.Invoke(() =>
                {
                    if(i == 19)
                    {
                        lblStatus.Content = "Finished";
                    }
                    taskProgressBar.Value = i;
                });
            }
        }
    }
}
