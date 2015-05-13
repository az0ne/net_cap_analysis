#ifndef QT_DEMO_H
#define QT_DEMO_H

#include <QtWidgets/QMainWindow>
#include "ui_qt_demo.h"
#include "capheader.h"

class qt_demo : public QMainWindow
{
	Q_OBJECT

public:
	qt_demo(QWidget *parent = 0);
	~qt_demo();
	void listAllDev();
	void hideAllWidget();
	void startListen();
	void clearAllWidget();

	QString getSMac(arp_header * ah);
	QString getDMac(arp_header * ah);
	QString getSIp(ip_header * ih);
	QString getDIp(ip_header * ih);
	QString getArpSIp(arp_header * ah);
	QString getArpDIp(arp_header * ah);
	QString getSipPTcp(ip_header * ih,tcp_header * th);
	QString getDipPTcp(ip_header * ih,tcp_header * th);
	QString getSipPUdp(ip_header * ih, udp_header * uh);
	QString getDipPUdp(ip_header * ih, udp_header * uh);

private slots:
	void on_comboBox_currentIndexChanged(int index);
	void on_pushButtonArp_clicked();
	void on_pushButtonIp_clicked();
	void on_pushButtonUdp_clicked();
	void on_pushButtonTcp_clicked();
	void on_pushButtonHttp_clicked();
	void on_pushButtonIcmp_clicked();
	void on_pushButtonStart_clicked();
	void on_pushButtonStop_clicked();
private:
	Ui::qt_demoClass ui;

	//pcap---->
	pcap_if_t* alldevs; // list of all devices
	pcap_if_t* d; // device you chose
	pcap_t* adhandle;
	char errbuf[PCAP_ERRBUF_SIZE]; //error buffer
	int i = 0;
	int inum;
	int packetNum = 0;
	struct pcap_pkthdr *pheader; /* pcap header */
	const u_char * pkt_data; /* pcap data */
	int res;
	bool onOff = false; //power switch identify


	int num_arp, num_ip, num_icmp, num_udp, num_tcp, num_http;

};

#endif // QT_DEMO_H
