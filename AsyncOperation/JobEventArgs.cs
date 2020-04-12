using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AsyncOperation
{
    class JobEventArgs:EventArgs
    {
        public Job Job { get; set; }
    }
}
