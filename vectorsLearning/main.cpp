#include <QCoreApplication>
#include <vector>
#include <QDebug>

using namespace std;
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    vector <int> mInt;
    for (int i = 0 ; i < 10 ; i++){
        mInt.push_back(i);
    }
    for (unsigned int i = 0 ; i <  mInt.size() ; i++){
        qDebug() << mInt.at(i);
    }
    qDebug() << mInt.back();

    // 2D vector'
    qDebug() << "/////////////////////vector of vectors////////////////////////////";
    vector<vector<int> > mStuff;
    // fill vectors
    for (int i = 0 ; i < 3 ; i++){
        vector<int> temp;
        for (int j = 0 ; j < 3 ; j++){
            temp.push_back(i);
        }
        mStuff.push_back(temp);
    }
    QString mString;
    for ( unsigned int i = 0 ; i < mStuff.size() ; i++){
        vector<int> temp;
        for ( unsigned int j = 0 ; j < mStuff[i].size(); j++){
            mString+=  mStuff[i][j];
        }
      //  mString += "\n";
    }
    qDebug() << mString;
    return a.exec();
}
