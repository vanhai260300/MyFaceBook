using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml;

namespace DomXML
{
    class DomClass
    {
        private String filename;
        private XmlDocument xmlDoc;
        public DomClass() { }
        public DomClass(String filename)
        {
            this.filename = filename;
        }
        public void setFilename(String filename)
        {
            this.filename = filename;
        }
        public void setXmlDoc()
        {
            XmlDocument xmlDoc1 = new XmlDocument();
            xmlDoc1.Load(@filename);
            this.xmlDoc = xmlDoc1;
        }
        public String getFilename()
        {
            return filename;
        }
        public XmlDocument getxmlDoc()
        {
            return xmlDoc;
        }

        public void SaoChep(String nodePath)
        {
            XmlNode node = xmlDoc.SelectSingleNode(nodePath);
            XmlNode newNode = node.CloneNode(true);
            Console.WriteLine(newNode.InnerXml);
        }
        public void addThuocTinh(String nodeName,String ten, String value)
        {
            XmlNode node = xmlDoc.SelectSingleNode(nodeName);
            ((XmlElement)node).SetAttribute(ten, value);
            Console.WriteLine(xmlDoc.SelectSingleNode("data-set/record").InnerXml);
        }
    }
}
