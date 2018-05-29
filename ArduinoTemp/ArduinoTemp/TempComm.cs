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
using System.IO;
using System.Diagnostics;
using Newtonsoft.Json.Linq;
using System.Net;
using CSGSI;
using CSGSI.Events;
using CSGSI.Nodes;

namespace ArduinoTemp
{

    public partial class TempComm : ServiceBase
    {
        static GameStateListener gsl;
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



            //start CSGO Stuff:
            CSGOint();
            //Start main "loop":
            System.Timers.Timer timer = new System.Timers.Timer();
            timer.Interval = 5000; // 5 seconds  
            timer.Elapsed += new System.Timers.ElapsedEventHandler(this.OnTimer);
            timer.Start();
        }

        protected override void OnStop()
        {
            serialPort1.Close();
        }
        public bool CsProgram()
        {
            //see if CS:GO is running
            Process[] pname = Process.GetProcessesByName("csgo");
            if (pname.Length > 0)
            {

                return true;
            }
            else
            {
                return false;
            }
        }
        //to loop:
        public void OnTimer(object sender, System.Timers.ElapsedEventArgs args)
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
                        if (kills == -1)
                        {
                            //99 is authentication value to ensure that the string is not invalid
                            serialPort1.Write(String.Format("0,{0},{1},99", temps, kills));
                        }
                        else
                        {
                            //CS:GO Mode:
                            //99 is authentication value to ensure that the string is not invalid
                            //really no difference, but i put this here for future use:
                            serialPort1.Write(String.Format("1,{0},{1},99", temps, kills));
                        }
                        // Console.WriteLine("{0}: {1}°F", sensor.Name, sensor.Value*1.8+32);
                        // Modified from a Open Hardware Monitor example
                    }

                }

            }




        }
        public void CSGOint()
        {
            gsl = new GameStateListener(3000);
            gsl.NewGameState += new NewGameStateHandler(OnNewGameState);
            if (!gsl.Start())
            {
                return;
            }
            //now listenting for info
            //add return here?
            return;
        }


        public int kills = -1;
        public void OnNewGameState(GameState gs)
        {
            kills = gs.Player.State.RoundKills;
        }
    }
}
