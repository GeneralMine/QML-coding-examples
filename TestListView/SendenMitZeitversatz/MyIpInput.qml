import QtQuick 2.3
import QtQuick.Controls 1.2
import QtQuick.Controls.Styles 1.3

Column
{
    id:col
    property alias myIp1 : ip1
    property alias myIp2 : ip2
    property alias myIp3 : ip3
    property alias myIp4 : ip4
    property alias myrow_ip: row_ip
    property alias myport: port

    anchors.centerIn: parent
    spacing:15

    Row
    {
        id:row_ip

        TextField
        {
            id:ip1
            placeholderText: qsTr("0")
            maximumLength: (3)
            implicitWidth: 90
            implicitHeight: 40
            font.pixelSize: 20

            focus: true
            onTextChanged:
            {
                if(ip1.length == 3)
                {
                    if(ip1.text>255)
                        ip1.text="";
                    else
                    {
                        ip1.focus = false;
                        ip2.focus = true;
                    }
                }
            }
        }
        Text
        {
            y:20
            color: "#ffffff"
            text:"."
        }
        TextField
        {
            id:ip2
            placeholderText: qsTr("0")
            implicitWidth: 90
            implicitHeight: 40
            maximumLength: (3)
            font.pixelSize: 20

            onTextChanged:
            {
                if(ip2.length == 3)
                {
                    if(ip2.text>255)
                        ip2.text="";
                    else
                    {
                        ip2.focus = false;
                        ip3.focus = true;
                    }
                }
            }
        }
        Text
        {
            y:20
            color: "#ffffff"
            text:"."
        }
        TextField
        {
            id:ip3
            placeholderText: qsTr("0")
            maximumLength: (3)
            implicitWidth: 90
            implicitHeight: 40
            font.pixelSize: 20

            onTextChanged:
            {
                if(ip3.length == 3)
                {
                    if(ip3.text>255)
                        ip3.text="";
                    else
                    {
                        ip3.focus = false;
                        ip4.focus = true;
                    }
                }
            }
        }
        Text
        {
            y:20
            color: "#ffffff"
            text:"."
        }
        TextField
        {
            id:ip4
            placeholderText: qsTr("0")
            maximumLength: (3)
            implicitWidth: 90
            implicitHeight: 40
            font.pixelSize: 20
            onTextChanged:
            {
                if(ip4.length == 3)
                {
                    if(ip4.text>255)
                        ip4.text="";
                    else
                        ip4.focus=false;
                    port.focus=true;
                }


            }
        }
    }
    TextField
    {
        id:port
        placeholderText: qsTr("Port")
        maximumLength: (6)
        implicitWidth: 90
        implicitHeight: 40
        font.pixelSize: 20
        x:(parent.width/2)-port.width/2
    }
}
