import QtQuick 2.12
import QtQuick.Window 2.2
import JieModule 1.0
import QtQuick.Controls 2.5
Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    JieJob{
        id:jieJob
        students:[
             JiePerson{
                 name:"zhan san"
                 age:27
             },
            JiePerson{
                name:"li si"
                age:17
            },
            JiePerson{
                name:"wang wu"
                age:37
            }

        ]

    }

    Button{
        id:button
        text:{ let students = jieJob.students
              return students[0].name}
        property string content:jieJob.studets[0]
        onClicked: {
            let students = jieJob.students
            for(let i = 0;i < students.length;i++)
            {
               console.log(students[i].name, ' ',students[i].age);
            }
        }



    }
}
