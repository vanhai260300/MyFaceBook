using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DomXML
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Dang Minh Hieu\n");

            DomClass domClass = new DomClass("../../DangMinhHieu.xml");
            domClass.setXmlDoc();
            
            Console.WriteLine("\nCâu 2: Sao chep Record có LastName=\"Smith\"");
            domClass.SaoChep("data-set/record[./LastName/text()='Smith']");
            
            Console.WriteLine("\nCâu 3: Them thuoc tinh Code cho Country");
            domClass.addThuocTinh("data-set/record/Country", "code", "0");
            Console.ReadKey();
        }
    }
}
