using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Linq;
using System.ServiceProcess;
using System.Text;
using System.Threading.Tasks;
using System.Management;
using OpenHardwareMonitor.Hardware;

namespace ArduinoTemp
{
    public partial class TempComm : ServiceBase
    {
        public TempComm()
        {
            InitializeComponent();

        }   

        protected override void OnStart(string[] args)
        {
            // Source: https://docs.microsoft.com/en-us/dotnet/framework/windows-services/walkthrough-creating-a-windows-service-application-in-the-component-designer#BK_CreateProject
            // Set up a timer to trigger every minute.  
            if (!serialPort1.IsOpen)
            {
                try
                {
                    serialPort1.Open();

                    
                }
                catch
                {
                    // serialPort1.Write(outputTemp);
                    // If not connected or other error, wait 1 minute:
                    System.Threading.Thread.Sleep(120000);
                }
            }

            System.Timers.Timer timer = new System.Timers.Timer();
            timer.Interval = 5000; // 60 seconds  
            timer.Elapsed += new System.Timers.ElapsedEventHandler(this.OnTimer);
            timer.Start();
        }

        protected override void OnStop()
        {
            serialPort1.Close();
        }

        public void OnTimer(object sender, System.Timers.ElapsedEventArgs args)
        {

                try
                {
                    // Change CPU to true to read CPU temps, will need to modify code and elevate permissions. Currently Set to GPU
                    Computer computer = new Computer() { CPUEnabled = false, GPUEnabled = true };
                    computer.Open();

                    foreach (IHardware hardware in computer.Hardware)
                    {
                        hardware.Update();

                        foreach (ISensor sensor in hardware.Sensors)
                        {
                            // Celsius is default unit
                            if (sensor.SensorType == SensorType.Temperature)
                            {
                                string temps = Convert.ToString(sensor.Value);
                                string.Format("{0:###}", temps);
                                serialPort1.Write(temps);
                                // Console.WriteLine("{0}: {1}°F", sensor.Name, sensor.Value*1.8+32);
                                // Modified from a Open Hardware Monitor example
                            }

                        }

                    }
                }
                catch
                {
                    // serialPort1.Write(outputTemp);
                    // If not connected or other error, wait 1 minute:
                    System.Threading.Thread.Sleep(120000);
                }
         

        }
    }
}
