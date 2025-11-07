using Newtonsoft.Json;
using Newtonsoft.Json.Linq;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Net.Http;
using System.Text;
using System.Threading.Tasks;

using Xamarin.Forms;
using Xamarin.Forms.Xaml;
using System.Timers;

namespace ZoomboTA
{




    [XamlCompilation(XamlCompilationOptions.Compile)]
    public partial class MainPage : ContentPage
    {
        
        public MainPage()
        {
            InitializeComponent();
        }

        private void Button_Reset(object sender, EventArgs e)
        {
            objTemp2.Text ="0";
            envTemp2.Text ="0";
            distance2.Text ="0";
            regDate2.Text = "0";
        }

        private async void Button_Load(object sender, EventArgs e)
        {            
            
            string json = await new HttpClient().GetStringAsync("http://zoomboapi.appspot.com/api/thermal/last"); //last one
            String[] words = json.Split('/');

            objTemp2.Text = words[1];
            envTemp2.Text = words[0];            
            distance2.Text= words[2];

            words[3] = words[3].Replace('T',' ').Substring(0,16);
            regDate2.Text = words[3];
            
        }
    }
}