import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 660
    property int changewidth:width
    height: 480
    title: qsTr("TableView")

    ListModel{
        id:listModel
        ListElement{
              PARTNO:"20201130"
              PLACE:"小山村"
              ADDRESS:"265454"
              JD:"105.0265"
              WD:"26.3265"
              BACKUP:" 2020-11-30 09:59:19"
        }
        ListElement{
                    PARTNO:"20201130"
                    PLACE:"大山村"
                    ADDRESS:"265454"
                    JD:"105.0265"
                    WD:"26.3265"
                    BACKUP:" 2020-11-30 09:59:19"
         }
    }

    DataTableView{
        id: dataListView
        anchors.fill: parent
        columnsWidth: parent.width/6
        headerList: ["日期","地点","地址","经度","纬度","备注"]
        model:listModel
        Component.onCompleted:{
               var c2 = dataListView.getColumnWidth(2)
               var c5 = dataListView.getColumnWidth(5)
               dataListView.setColumnWidth(2,c2-50)
               dataListView.setColumnWidth(5,c5+50)
               var c3 = dataListView.getColumnWidth(2)
               var c4 = dataListView.getColumnWidth(5)
               console.log(c3 +" " + c4);
           }
    }
    onWidthChanged: {
        dataListView.setColumnWidth(0,width/6)
        dataListView.setColumnWidth(1,width/6)
        dataListView.setColumnWidth(2,width/6 - 50)
        dataListView.setColumnWidth(3,width/6)
        dataListView.setColumnWidth(4,width/6)
        dataListView.setColumnWidth(5,width/6 + 50)
    }
}
