﻿//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a tool.
//     Runtime Version:4.0.30319.42000
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------

namespace EmployeeForm.EmpService {
    
    
    [System.CodeDom.Compiler.GeneratedCodeAttribute("System.ServiceModel", "4.0.0.0")]
    [System.ServiceModel.ServiceContractAttribute(ConfigurationName="EmpService.IEmployeeService")]
    public interface IEmployeeService {
        
        [System.ServiceModel.OperationContractAttribute(Action="http://tempuri.org/IEmployeeService/GetAllEmployees", ReplyAction="http://tempuri.org/IEmployeeService/GetAllEmployeesResponse")]
        EmployeeForm.Data.Employee[] GetAllEmployees();
        
        [System.ServiceModel.OperationContractAttribute(Action="http://tempuri.org/IEmployeeService/GetAllEmployees", ReplyAction="http://tempuri.org/IEmployeeService/GetAllEmployeesResponse")]
        System.Threading.Tasks.Task<EmployeeForm.Data.Employee[]> GetAllEmployeesAsync();
        
        [System.ServiceModel.OperationContractAttribute(Action="http://tempuri.org/IEmployeeService/UpdateInsertEmployeeDetails", ReplyAction="http://tempuri.org/IEmployeeService/UpdateInsertEmployeeDetailsResponse")]
        int UpdateInsertEmployeeDetails(EmployeeForm.Data.Employee employee);
        
        [System.ServiceModel.OperationContractAttribute(Action="http://tempuri.org/IEmployeeService/UpdateInsertEmployeeDetails", ReplyAction="http://tempuri.org/IEmployeeService/UpdateInsertEmployeeDetailsResponse")]
        System.Threading.Tasks.Task<int> UpdateInsertEmployeeDetailsAsync(EmployeeForm.Data.Employee employee);
    }
    
    [System.CodeDom.Compiler.GeneratedCodeAttribute("System.ServiceModel", "4.0.0.0")]
    public interface IEmployeeServiceChannel : EmployeeForm.EmpService.IEmployeeService, System.ServiceModel.IClientChannel {
    }
    
    [System.Diagnostics.DebuggerStepThroughAttribute()]
    [System.CodeDom.Compiler.GeneratedCodeAttribute("System.ServiceModel", "4.0.0.0")]
    public partial class EmployeeServiceClient : System.ServiceModel.ClientBase<EmployeeForm.EmpService.IEmployeeService>, EmployeeForm.EmpService.IEmployeeService {
        
        public EmployeeServiceClient() {
        }
        
        public EmployeeServiceClient(string endpointConfigurationName) : 
                base(endpointConfigurationName) {
        }
        
        public EmployeeServiceClient(string endpointConfigurationName, string remoteAddress) : 
                base(endpointConfigurationName, remoteAddress) {
        }
        
        public EmployeeServiceClient(string endpointConfigurationName, System.ServiceModel.EndpointAddress remoteAddress) : 
                base(endpointConfigurationName, remoteAddress) {
        }
        
        public EmployeeServiceClient(System.ServiceModel.Channels.Binding binding, System.ServiceModel.EndpointAddress remoteAddress) : 
                base(binding, remoteAddress) {
        }
        
        public EmployeeForm.Data.Employee[] GetAllEmployees() {
            return base.Channel.GetAllEmployees();
        }
        
        public System.Threading.Tasks.Task<EmployeeForm.Data.Employee[]> GetAllEmployeesAsync() {
            return base.Channel.GetAllEmployeesAsync();
        }
        
        public int UpdateInsertEmployeeDetails(EmployeeForm.Data.Employee employee) {
            return base.Channel.UpdateInsertEmployeeDetails(employee);
        }
        
        public System.Threading.Tasks.Task<int> UpdateInsertEmployeeDetailsAsync(EmployeeForm.Data.Employee employee) {
            return base.Channel.UpdateInsertEmployeeDetailsAsync(employee);
        }
    }
}