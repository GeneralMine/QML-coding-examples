import QtQuick 2.0



ListModel
{
    property alias myContactModel : contactmodel  //zugriff von anderer datei aus möglich machen

    id:contactmodel
    ListElement
    {
        name:"Element0"
        number:"0"
    }
    ListElement
    {
        name:"Element1"
        number:"1"
    }
    ListElement
    {
        name:"Element2"
        number:"2"
    }
}
