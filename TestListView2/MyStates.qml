import QtQuick 2.0

Item
{
    property Item window1
    property Item listenAbbildung
    property Item eintragHinzufügen
    property Item root


    state:"eins"

    states:
        [
        State
        {
            name:"eins"
            /*daPropertyChanges
            {
                target:window1
                x:0
            }*/
            PropertyChanges
            {
                target:listenAbbildung
                x:window1.width
            }
        },
        State
        {

            name:"zwei"
           /* PropertyChanges
            {
                target:window1
                x:-listenAbbildung.width
            }*/
            PropertyChanges
            {
                target:listenAbbildung
                x:window1.width-listenAbbildung.width
            }
            PropertyChanges
            {
                target:eintragHinzufügen
                y:0-eintragHinzufügen.height
            }
        },
        State
        {
            name: "drei"

            PropertyChanges
            {
                target:window1
                x:-listenAbbildung.width
            }
            PropertyChanges
            {
                target:listenAbbildung
                x:window1.width-listenAbbildung.width
            }
            PropertyChanges
            {
                target:eintragHinzufügen

                y:0
            }
        }
        ]
    transitions:
        [
        Transition
        {
            from: "eins"
            to: "zwei"
            NumberAnimation { easing.type: Easing.InOutCubic; properties: "x"; duration:350 }
        },
        Transition
        {
            from: "zwei"
            to: "eins"
            NumberAnimation { easing.type: Easing.InOutCubic; properties: "x"; duration:350 }
        },
        Transition
        {
            from: "zwei"
            to: "drei"
            NumberAnimation { easing.type: Easing.InOutCubic; properties: "y"; duration:350 }
        },
        Transition
        {
            from: "drei"
            to: "zwei"
            NumberAnimation { easing.type: Easing.InOutCubic; properties: "y"; duration:350 }
        }

        ]
}
