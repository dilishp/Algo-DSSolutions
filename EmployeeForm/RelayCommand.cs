using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Input;

namespace EmployeeForm
{
    public class RelayCommand : ICommand
    {
        public event EventHandler CanExecuteChanged;
        private Action ExecuteCommand;
        private Func<bool> CanExecuteCommand;

        public RelayCommand(Action executeCommand,Func<bool> canExecute)
        {
            ExecuteCommand = executeCommand;
            CanExecuteCommand = canExecute;
        }

        public bool CanExecute(object parameter)
        {
            if(CanExecuteCommand != null)
            {
                return CanExecuteCommand();
            }
            return true;
        }

        public void Execute(object parameter)
        {
            if(ExecuteCommand != null)
            {
                ExecuteCommand();
            }
        }

        public void RaiseCanExecuteChanged()
        {
            if (CanExecuteChanged != null)
                CanExecuteChanged(this, EventArgs.Empty);
        }
    }
}
