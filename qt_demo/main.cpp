#include "qt_demo.h"

#include "pcap.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	qt_demo w;
	w.show();
	//w.test01();

	return a.exec();
}
