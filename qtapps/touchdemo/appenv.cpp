#include "appenv.h"

QString AppEnv::imgPath = "/home/tsuibin/Pictures/deepin-wallpapers/";
QString currentImg = "";
int AppEnv::currentImageIndex = 0;
int AppEnv::imgCount = 0;

QStringList AppEnv::imgList;

AppEnv::AppEnv()
{

}

QStringList AppEnv::initImgList()
{

	QDir pdir;
	pdir.setPath(imgPath);
	//QFileInfoList t = pdir.entryInfoList(QDir::Files);
	//qDebug() << pdir.entryList( QDir::Files );
	imgList = pdir.entryList(QDir::Files);
	AppEnv::imgCount = pdir.entryList(QDir::Files).size();
	return pdir.entryList(QDir::Files);

}
