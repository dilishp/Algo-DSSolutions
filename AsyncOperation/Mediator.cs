using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AsyncOperation
{
    class Mediator
    {
        private static Mediator _Instance = new Mediator();

        private Mediator()
        {

        }
        public static Mediator GetInstance
        {
            get
            {
                return _Instance;
            }
        }

        public event EventHandler<JobEventArgs> JobChangeEventHandler;
        public void UpdateListofEmployees(object sender, Job job)
        {
            if(JobChangeEventHandler != null)
            {
                JobChangeEventHandler(sender, new JobEventArgs() { Job = job });
            }
        }

    }
}
