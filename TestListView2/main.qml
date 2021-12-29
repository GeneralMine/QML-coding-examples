import QtQuick 2.0
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2

ApplicationWindow {
    title: qsTr("Hello World")
    width: 640
    height: 480
    visible: true
    id:root

    Rectangle
    {
        id:window1
        height:parent.height
        width: parent.width
        x:0
        y:0
        Button
        {
            x:400
            y:75
            text:"index und inhalt"
            onClicked: console.log(listModel.myContactModel.get(liste.currentIndex).name)//console.log(liste.currentIndex)
        }
        Button
        {
            x:400
            y:100
            text:"test"
            onClicked:
                if(mystates.state=="eins")
                    mystates.state="zwei"
                else
                    mystates.state="eins"
        }
    }
    Rectangle
    {
        id:listenAbbildung
        height:parent.height
        width: parent.width/5
        x: 0
        y:0
        color:"grey"
        ListView
        {
            x:10
            id:liste
            width:100
            height: 200
            model:ContactModel{id:listModel}
            delegate:contactDelegate
            focus:true
            highlight: highlightBar
            preferredHighlightBegin: 90
            preferredHighlightEnd: 110
            highlightFollowsCurrentItem: true
            highlightRangeMode: ListView.StrictlyEnforceRange
            currentIndex: 1
        }
        Rectangle
        {
            color:"grey"
            x:0
            y:0
            height: 50
            width: eintragHinzufügen.width
        }
        Button
        {
            id:buttonEintragDazu
            width:listenAbbildung.width/3*2
            x:listenAbbildung.width/3*0.5
            y:10
            text:"eintrag dazu"
            onClicked:
            mystates.state="drei"
        }
    }
    Rectangle
    {
        id:eintragHinzufügen
        x:root.width -eintragHinzufügen.width
        y:0-eintragHinzufügen.height
        height: root.height/3
        width: listenAbbildung.width
        color:"black"
        TextField
        {
            id:textName
            width:listenAbbildung.width/3*2
            x:listenAbbildung.width/3*0.5
            y:eintragHinzufügen.height/4-eintragHinzufügen.height/8
            placeholderText: "name"
        }
        TextField
        {
            id:textNumber
            width:listenAbbildung.width/3*2
            x:listenAbbildung.width/3*0.5
            y:eintragHinzufügen.height/4*2-eintragHinzufügen.height/8
            placeholderText: "Nummer"
        }
        Button
        {
            width:listenAbbildung.width/3*2
            x:listenAbbildung.width/3*0.5
            y:eintragHinzufügen.height/4*3-eintragHinzufügen.height/8
            text:"add"
            onClicked:
            {
                listModel.myContactModel.append({"name": textName.text, "number": textNumber.text})// zurgriff auf listModel
                mystates.state="zwei"
            }
        }
    }
    MyStates
    {
        id:mystates
        window1: window1
        listenAbbildung: listenAbbildung
        eintragHinzufügen:eintragHinzufügen
    }
    Component
    {
        id: highlightBar
        Rectangle
        {
            width: liste.width; height: 40
            color: "#FFFF88"
            border.color: "black"
            x:-8
            y:-20
        }
    }
    Component
    {
        id:contactDelegate
        Item
        {
            id: wrapper
            width:180
            height: 40
            Text{text: name + ": " + number}
            MouseArea
            {
                anchors.fill: parent
                onClicked:
                {
                    liste.currentIndex=index
                    console.log(index)
                }
            }
        }
    }
}
