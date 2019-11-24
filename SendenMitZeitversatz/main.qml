import QtQuick 2.3
import QtQuick.Controls 1.2

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    onClosing: MySocket.kill();

    Rectangle
    {
        id: anmeldung
        anchors.fill: parent
        MyIpInput
        {
            id:ip_input
        }

        Button
        {
            id:button1
            text:"test"
            x:parent.width/2-width/2
            y:parent.height/3
            onClicked:
            {
                anmeldung.visible=false;
                MyDatabase.ipundportspeichern(ip_input.myIp1.text,ip_input.myIp2.text,ip_input.myIp3.text,ip_input.myIp4.text,ip_input.myport.text);
                //connecting.visible=true;
                MySocket.doConnect(ip_input.myIp1.text,ip_input.myIp2.text,ip_input.myIp3.text,ip_input.myIp4.text,ip_input.myport.text);

            }
        }


    }
    Rectangle
    {
        id:datensenden
        visible: false
        anchors.fill: parent
        color:"blue"

        Button
        {
            x:parent.width/2-width/2
            y:parent.height/3
            id:button2
            text:"set"
            onClicked:
                MyDatabase.fetchDataFromDatabase("set");
        }
        Button
        {
            x:parent.width/2-width/2
            anchors.top:button2.bottom
            id:button3
            text:"get"

            onClicked:
                MyDatabase.fetchDataFromDatabase("get");
        }
    }
    Text
    {
        id:isonceted
        text:"not connected"
        anchors.right: parent.right
        anchors.bottom: parent.bottom
    }

    Connections
    {
        target: MySocket
        onConnectedqml:
        {
            anmeldung.visible=false;
            datensenden.visible=true;
            isonceted.text="connected";
        }
        onNotConnectedqml:
        {
            anmeldung.visible=true;
            datensenden.visible=false;
            isonceted.text="not connected";
        }

    }
    Connections
    {
        target: MyDatabase
        onIpAndPortEinschrieben:
        {
            ip_input.myIp1.text=ip1;
            ip_input.myIp2.text=ip2;
            ip_input.myIp3.text=ip3;
            ip_input.myIp4.text=ip4;
            ip_input.myport.text=port;
        }
    }


}
