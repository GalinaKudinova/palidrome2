#include <QFile>
#include <QDebug>
#include <QString>
#include <iostream>
#include <QCoreApplication>
#include <QTextStream>





bool checkPalidrome(QString line){

    // return equal(line.begin(), line.end(), line.rbegin());

      int line_size;
      bool ok=true;

      line_size=line.length();
      line=line.simplified();
      for (int i=0;i<line_size/2;++i)
      {
          if(line[i]!=line[line_size-i-1])
          {
          ok=false;
          }
      }

     return ok;
}


void writeFile (bool flag, QString line,QString FileNameOut){
     QFile file(FileNameOut);
     if (file.open(QFile::WriteOnly |QFile::Append )){
         QTextStream out(&file);
       if (flag == true)
         {
             qDebug()<<"yes, it is a palindrome: "<< line << "\r\n"<<endl;
            out<<"yes, it is a palindrome: "<< line << "\r\n"<<endl;
         } else {
             qDebug()<<"this is not a palindrome "<< line << "\r\n"<<endl;
             out<<"this is not a palindrome "<< line << "\r\n"<<endl;
         }
      }
      file.close();
}



int main()
{
    bool flag= true;

      QFile ReadFile("input2.txt");
      QFile FileOut("Output.txt");
      QString line;

      QString FileNameOut="Output.txt";
      QTextStream in(&ReadFile);

      FileOut.remove();

     if (ReadFile.open(QFile::ReadOnly| QFile::Text)) {
          while(!in.atEnd()) {
          QString line = in.readLine();     //читаем из файла


           flag = checkPalidrome(line);            //  полиндром или нет??
           qDebug()<< " flag is :"<< flag << endl;
           writeFile ( flag, line, FileNameOut);    // пишем отчет
           flag = true;
          }
     ReadFile.close();
     }
      return 0;
}


