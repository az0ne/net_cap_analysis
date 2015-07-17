#include "qt_demo.h"

qt_demo::qt_demo(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	hideAllWidget();
	listAllDev();
}

qt_demo::~qt_demo()
{

}

//SLOT
void qt_demo::hideAllWidget(){
	ui.tableWidgetTcp->hide();
	ui.tableWidgetHttp->hide();
	ui.tableWidgetIcmp->hide();
	ui.tableWidgetUdp->hide();
	ui.tableWidgetIp->hide();
	ui.tableWidgetArp->hide();
	ui.tableWidgetImage->hide();
	ui.tableWidgetFile->hide();
}

void qt_demo::on_pushButtonArp_clicked(){
	ui.tableWidgetArp->show();
	ui.tableWidgetHttp->hide();
	ui.tableWidgetIcmp->hide();
	ui.tableWidgetTcp->hide();
	ui.tableWidgetUdp->hide();
	ui.tableWidgetIp->hide();
	ui.tableWidgetImage->hide();
	ui.tableWidgetFile->hide();
}

void qt_demo::on_pushButtonIp_clicked(){
	ui.tableWidgetIp->show();
	ui.tableWidgetHttp->hide();
	ui.tableWidgetIcmp->hide();
	ui.tableWidgetTcp->hide();
	ui.tableWidgetUdp->hide();
	ui.tableWidgetArp->hide();
	ui.tableWidgetImage->hide();
	ui.tableWidgetFile->hide();
}

void qt_demo::on_pushButtonUdp_clicked(){
	ui.tableWidgetUdp->show();
	ui.tableWidgetHttp->hide();
	ui.tableWidgetIcmp->hide();
	ui.tableWidgetTcp->hide();
	ui.tableWidgetIp->hide();
	ui.tableWidgetArp->hide();
	ui.tableWidgetImage->hide();
	ui.tableWidgetFile->hide();
}

void qt_demo::on_pushButtonTcp_clicked(){
	ui.tableWidgetTcp->show();
	ui.tableWidgetHttp->hide();
	ui.tableWidgetIcmp->hide();
	ui.tableWidgetUdp->hide();
	ui.tableWidgetIp->hide();
	ui.tableWidgetArp->hide();
	ui.tableWidgetImage->hide();
	ui.tableWidgetFile->hide();
}

void qt_demo::on_pushButtonHttp_clicked(){
	ui.tableWidgetHttp->show();
	ui.tableWidgetTcp->hide();
	ui.tableWidgetIcmp->hide();
	ui.tableWidgetUdp->hide();
	ui.tableWidgetIp->hide();
	ui.tableWidgetArp->hide();
	ui.tableWidgetImage->hide();
	ui.tableWidgetFile->hide();
}

void qt_demo::on_pushButtonIcmp_clicked(){
	ui.tableWidgetIcmp->show();
	ui.tableWidgetHttp->hide();
	ui.tableWidgetTcp->hide();
	ui.tableWidgetUdp->hide();
	ui.tableWidgetIp->hide();
	ui.tableWidgetArp->hide();
	ui.tableWidgetImage->hide();
	ui.tableWidgetFile->hide();
}

void qt_demo::on_pushButtonStart_clicked(){
	if (onOff == false){
		onOff = true;
		ui.labelPacketNum->setText("0");
		startListen();
	}
	
}

void qt_demo::on_pushButtonStop_clicked(){
		onOff = false;
		ui.labelStatus->setText("Stoped");
}

void qt_demo::on_pushButtonImage_clicked(){
	ui.tableWidgetImage->show();
	ui.tableWidgetIcmp->hide();
	ui.tableWidgetHttp->hide();
	ui.tableWidgetTcp->hide();
	ui.tableWidgetUdp->hide();
	ui.tableWidgetIp->hide();
	ui.tableWidgetArp->hide();
	ui.tableWidgetFile->hide();
}

void qt_demo::on_pushButtonFile_clicked(){
	ui.tableWidgetFile->show();
	ui.tableWidgetImage->hide();
	ui.tableWidgetIcmp->hide();
	ui.tableWidgetHttp->hide();
	ui.tableWidgetTcp->hide();
	ui.tableWidgetUdp->hide();
	ui.tableWidgetIp->hide();
	ui.tableWidgetArp->hide();
}

void qt_demo::on_comboBox_currentIndexChanged(int index)
{
	inum = ui.comboBox->currentIndex();
	for (d = alldevs, i = 0; i < inum; d = d->next, i++); /* jump to the selected interface */
}

//pcap 
void qt_demo::listAllDev() //list all network dev
{
	ui.comboBox->clear();
	clearAllWidget();
	pcap_findalldevs_ex(PCAP_SRC_IF_STRING, NULL, &alldevs, errbuf);
	for (d = alldevs; d; d = d->next){
		if (d->description){
			ui.comboBox->addItem(d->description);
		}
	}
}

//pcap->start listening & capture packet
void qt_demo::startListen(){

	clearAllWidget(); //clear old data
	if ((adhandle = pcap_open(d->name, /* the interface name */
		65536, /* length of packet that has to be retained */
		PCAP_OPENFLAG_PROMISCUOUS, /* promiscuous mode */
		1000, /* read time out */
		NULL, /* auth */
		errbuf /* error buffer */
		)) == NULL){
		ui.labelStatus->setText("dev error");
	}
	//pcap_freealldevs(alldevs);
	ui.labelStatus->setText("Listening");

	while (onOff) {
		if (!onOff){
			ui.labelStatus->setText("Stoped");
			break;
		}
		QApplication::processEvents();//
		res = pcap_next_ex(adhandle, &pheader, &pkt_data);
		if (res == 0)
			continue; // read time out
		ether_header * eheader = (ether_header*)pkt_data; // transform packet data to ethernet header [14 bytes]
		if (eheader->ether_type == htons(ARP_PROTOCAL)){		//********************* filter arp packet
			arp_header * ah = (arp_header*)(pkt_data + 14);
			arpProcessor(ah);
		}
		if (eheader->ether_type == htons(ETHERTYPE_IP)) { // ip packet only 
			ip_header * ih = (ip_header*)(pkt_data + 14); //********************* filter ip header 
			ipProcessor(ih);
			if (ih->proto == htons(TCP_PROTOCAL)) { //************************filter tcp header
				tcp_header * th = (tcp_header*)(pkt_data + 14 + 20);
				tcpProcessor(ih, th);
				if (ntohs(th->th_sport) == 80 || ntohs(th->th_dport) == 80){ //**********************filter http packet
					httpProcessor(ih, th);
				}
			}
			if (ih->proto == htons(UDP_PROTOCAL)){ //**********************filter udp header
				udp_header * uh = (udp_header*)(pkt_data + 14 + 20);
				udpProcessor(ih, uh);
			}
			if (ih->proto == htons(ICMP_PROTOCAL)){ //************************filter icmp packet
				icmp_header * icmp_h = (icmp_header*)(pkt_data + 14 + 20);
				icmpProcessor(ih, icmp_h);
			}
		}
	}
}

void qt_demo::arpProcessor(arp_header * ah){
	num_arp++;
	ui.tableWidgetArp->setRowCount(num_arp);
	int temp = 0;
	ui.tableWidgetArp->setItem(num_arp - 1, temp++, new QTableWidgetItem(QString::number(ntohs(ah->hard_type))));
	ui.tableWidgetArp->setItem(num_arp - 1, temp++, new QTableWidgetItem(QString::number(ntohs(ah->proto_type))));
	ui.tableWidgetArp->setItem(num_arp - 1, temp++, new QTableWidgetItem(QString::number(ah->hard_len)));
	ui.tableWidgetArp->setItem(num_arp - 1, temp++, new QTableWidgetItem(QString::number(ah->proto_len)));
	ui.tableWidgetArp->setItem(num_arp - 1, temp++, new QTableWidgetItem(QString::number(ntohs(ah->op))));
	ui.tableWidgetArp->setItem(num_arp - 1, temp++, new QTableWidgetItem(getSMac(ah)));
	ui.tableWidgetArp->setItem(num_arp - 1, temp++, new QTableWidgetItem(getArpSIp(ah)));
	ui.tableWidgetArp->setItem(num_arp - 1, temp++, new QTableWidgetItem(getDMac(ah)));
	ui.tableWidgetArp->setItem(num_arp - 1, temp++, new QTableWidgetItem(getArpDIp(ah)));
	ui.labelPacketNum->setText(QString::number(++packetNum));

}

void qt_demo::ipProcessor(ip_header *ih){
	num_ip++;
	ui.tableWidgetIp->setRowCount(num_ip);
	int temp = 0;
	ui.tableWidgetIp->setItem(num_ip - 1, temp++, new QTableWidgetItem(getSIp(ih)));
	ui.tableWidgetIp->setItem(num_ip - 1, temp++, new QTableWidgetItem(getDIp(ih)));
	ui.tableWidgetIp->setItem(num_ip - 1, temp++, new QTableWidgetItem(QString::number(ih->tos)));
	ui.tableWidgetIp->setItem(num_ip - 1, temp++, new QTableWidgetItem(QString::number(ntohs(ih->tlen))));
	ui.tableWidgetIp->setItem(num_ip - 1, temp++, new QTableWidgetItem(QString::number(ntohs(ih->identification))));
	ui.tableWidgetIp->setItem(num_ip - 1, temp++, new QTableWidgetItem(QString::number(ih->ttl)));
	ui.tableWidgetIp->setItem(num_ip - 1, temp++, new QTableWidgetItem(QString::number(ih->proto)));
	ui.tableWidgetIp->setItem(num_ip - 1, temp++, new QTableWidgetItem(QString::number(ntohs(ih->crc))));
	ui.labelPacketNum->setText(QString::number(++packetNum));
}

void qt_demo::tcpProcessor(ip_header * ih, tcp_header * th){
	num_tcp++;
	ui.tableWidgetTcp->setRowCount(num_tcp);
	int temp = 0;
	ui.tableWidgetTcp->setItem(num_tcp - 1, temp++, new QTableWidgetItem(getSIp(ih)));
	ui.tableWidgetTcp->setItem(num_tcp - 1, temp++, new QTableWidgetItem(QString::number(ntohs(th->th_sport))));
	ui.tableWidgetTcp->setItem(num_tcp - 1, temp++, new QTableWidgetItem(getDIp(ih)));
	ui.tableWidgetTcp->setItem(num_tcp - 1, temp++, new QTableWidgetItem(QString::number(ntohs(th->th_dport))));
	ui.tableWidgetTcp->setItem(num_tcp - 1, temp++, new QTableWidgetItem(QString::number(ntohl(th->th_seq))));
	ui.tableWidgetTcp->setItem(num_tcp - 1, temp++, new QTableWidgetItem(QString::number(ntohl(th->th_ack))));
	ui.tableWidgetTcp->setItem(num_tcp - 1, temp++, new QTableWidgetItem(QString::number(ntohs(th->th_window))));
	ui.tableWidgetTcp->setItem(num_tcp - 1, temp++, new QTableWidgetItem(QString::number(ntohs(th->th_sum))));
	ui.tableWidgetTcp->setItem(num_tcp - 1, temp++, new QTableWidgetItem(QString::number(ntohs(th->th_urp))));
}

void qt_demo::httpProcessor(ip_header * ih, tcp_header * th){
	int http_len = ntohs(ih->tlen) - 20 - 20; // http部分的文本长度，减去ip和tcp头部长度 
	char* http_pkt_data = (char*)(pkt_data + 14 + 20 + 20);//应用层data
	int find_http = false;
	int n = 0;
	for (; n < http_len; n++){
		if (!find_http && ((n + 3 < http_len && strncmp(http_pkt_data + n, "GET", strlen("GET")) == 0)
			|| (n + 4 < http_len && strncmp(http_pkt_data + n, "POST", strlen("POST")) == 0))){
			find_http = true; break;
		}
		if (n > 4) break;
	}
	if (find_http){
		int blank = 0;
		int temp = 0;
		int ptr = 0;
		num_http++;
		QString httpQ;//http request
		QString httpF;//http request form
		ui.tableWidgetHttp->setRowCount(num_http);
		for (; ptr < http_len - 2; ptr++){ //http request line
			if (blank == 0 && strncmp(http_pkt_data + ptr, " ", strlen(" ")) == 0){ //first blank, next is url
				blank++;
				httpQ.append(" ");
				continue;
			}
			if (blank == 1 && strncmp(http_pkt_data + ptr, " ", strlen(" ")) == 0){ //second blacnk, next is release
				blank++;
				httpQ.append(" ");
				continue;
			}
			if ((int)(http_pkt_data[ptr]) == 13 && (int)(http_pkt_data[ptr + 1]) == 10){ //first CRLF
				ptr = ptr + 2;
				httpQ.append(" ");
				break;
			}
			httpQ.append(http_pkt_data[ptr]);
		}
		ui.tableWidgetHttp->setItem(num_http - 1, temp++, new QTableWidgetItem(httpQ));
		ui.tableWidgetHttp->setItem(num_http - 1, temp++, new QTableWidgetItem(getSIp(ih)));
		ui.tableWidgetHttp->setItem(num_http - 1, temp++, new QTableWidgetItem(QString::number(ntohs(th->th_sport))));
		ui.tableWidgetHttp->setItem(num_http - 1, temp++, new QTableWidgetItem(getDIp(ih)));
		ui.tableWidgetHttp->setItem(num_http - 1, temp++, new QTableWidgetItem(QString::number(ntohs(th->th_dport))));
		for (; ptr < http_len - 4; ptr++){
			if ((int)(http_pkt_data[ptr]) == 13 && (int)(http_pkt_data[ptr + 1]) == 10 &&
				(int)(http_pkt_data[ptr + 2]) == 13 && (int)(http_pkt_data[ptr + 3]) == 10){ // http request form
				ptr = ptr + 4;
				break;
			}
		}
		for (; ptr < http_len; ptr++){
			httpF.append(http_pkt_data[ptr]);
		}
		ui.tableWidgetHttp->setItem(num_http - 1, temp++, new QTableWidgetItem(httpF));
	}
	//************************** filter image packet
	
	if (find_http && !find_image){
		for (n = 0; n < http_len; n++){ //111
			if ((n + 4 < http_len && strncmp(http_pkt_data + n, ".jpg", strlen(".jpg")) == 0)){ //image request
				find_image = true;
				img.ack = ntohl(th->th_seq) + ntohs(ih->tlen) - 40;
				img.writing = true;
				img.imgType = 1;
				break;
			}
			if ((n + 4 < http_len && strncmp(http_pkt_data + n, ".png", strlen(".png")) == 0)){ //image request
				find_image = true;
				img.ack = ntohl(th->th_seq) + ntohs(ih->tlen) - 40;
				img.writing = true;
				img.imgType = 2;
				break;
			}
			if ((int)(http_pkt_data[n]) == 13 && (int)(http_pkt_data[n + 1]) == 10){
				break;
			}
		}
	}

	if (find_image && (ntohl(th->th_ack) == img.ack)){
		if (img.seg == 0){
			char filename[_MAX_PATH];// "C:\\Users\\ckv1\\Documents\\Visual Studio 2013\\Projects\\qt_demo\\qt_demo\\data\\";
			_getcwd(filename, _MAX_PATH);
			strcat(filename, "\\data\\");
			char c1[20];
			sprintf(c1, "%lu", ntohl(th->th_ack));
			strcat(filename, c1);
			if (img.imgType == 1){
				strcat(filename, ".jpg");
			}
			if (img.imgType == 2){
				strcat(filename, ".png");
			}
			fp_image = fopen(filename, "ab");//open image file, prepare to write image
			strcpy(img.filename, filename);
			int temp = 0;
			for (; temp < http_len - 4; temp++){
				if ((int)(http_pkt_data[temp]) == 13 && (int)(http_pkt_data[temp + 1]) == 10 &&
					(int)(http_pkt_data[temp + 2]) == 13 && (int)(http_pkt_data[temp + 3]) == 10){ // http request form
					temp = temp + 4;
					break;
				}
			}
			for (; temp < http_len; temp++){
				fprintf(fp_image, "%c", http_pkt_data[temp]);
				img.size++;
			}
			img.seg++;
		}
		else{
			int temp2 = 0;
			for (; temp2 < http_len; temp2++){
				fprintf(fp_image, "%c", http_pkt_data[temp2]);
				img.size++;
			}
			img.seg++;
		}
		if (ntohs(th->th_len_resv_code) == 20504 &&
			((img.imgType == 1 && (int)http_pkt_data[http_len - 2] == -1 && (int)http_pkt_data[http_len - 1] == -39) ||
			(img.imgType == 2 && strncmp(http_pkt_data + (http_len - 8), "IEND", strlen("IEND")) == 0))){//save image over

			fclose(fp_image);
			int temp = 0;
			num_image++;
			ui.tableWidgetImage->setRowCount(num_image);
			QTableWidgetItem *qtimg = new QTableWidgetItem();
			qtimg->setIcon(QIcon(QPixmap(img.filename)));
			qtimg->setTextAlignment(Qt::AlignVCenter);
			ui.tableWidgetImage->setItem(num_image - 1, temp++, qtimg);
			ui.tableWidgetImage->setItem(num_image - 1, temp++, new QTableWidgetItem(getSIp(ih)));
			ui.tableWidgetImage->setItem(num_image - 1, temp++, new QTableWidgetItem(QString::number(ntohs(th->th_sport))));
			ui.tableWidgetImage->setItem(num_image - 1, temp++, new QTableWidgetItem(getDIp(ih)));
			ui.tableWidgetImage->setItem(num_image - 1, temp++, new QTableWidgetItem(QString::number(ntohs(th->th_dport))));
			ui.tableWidgetImage->setItem(num_image - 1, temp++, new QTableWidgetItem(QString::number(img.size)));
			find_image = false;
			img.writing = false;
			img.seg = 0;
			img.size = 0;
		}
	}
	//************************** filter file packet
	if (find_http && !find_file){
		for (n = 0; n < http_len; n++){
			if ((n + 4 < http_len && strncmp(http_pkt_data + n, ".doc", strlen(".doc")) == 0)){
				find_file = true;
				fil.ack = ntohl(th->th_seq) + ntohs(ih->tlen) - 40;
				fil.writing = true;
				strcpy(fil.fileType, ".doc");
				break;
			}
			if ((n + 4 < http_len && strncmp(http_pkt_data + n, ".rar", strlen(".rar")) == 0)){
				find_file = true;
				fil.ack = ntohl(th->th_seq) + ntohs(ih->tlen) - 40;
				fil.writing = true;
				strcpy(fil.fileType, ".rar");
				break;
			}
			if ((n + 4 < http_len && strncmp(http_pkt_data + n, ".zip", strlen(".zip")) == 0)){
				find_file = true;
				fil.ack = ntohl(th->th_seq) + ntohs(ih->tlen) - 40;
				fil.writing = true;
				strcpy(fil.fileType, ".zip");
				break;
			}
			if ((n + 4 < http_len && strncmp(http_pkt_data + n, ".exe", strlen(".exe")) == 0)){
				find_file = true;
				fil.ack = ntohl(th->th_seq) + ntohs(ih->tlen) - 40;
				fil.writing = true;
				strcpy(fil.fileType, ".exe");
				break;
			}
			if ((n + 4 < http_len && strncmp(http_pkt_data + n, ".txt", strlen(".txt")) == 0)){
				find_file = true;
				fil.ack = ntohl(th->th_seq) + ntohs(ih->tlen) - 40;
				fil.writing = true;
				strcpy(fil.fileType, ".txt");
				break;
			}
			if ((int)(http_pkt_data[n]) == 13 && (int)(http_pkt_data[n + 1]) == 10){
				break;
			}
		}
		if (find_file){
			_getcwd(fil.filename, _MAX_PATH);
			strcat(fil.filename, "\\data\\");
			char c1[20];
			sprintf(c1, "%lu", ntohl(th->th_ack));
			strcat(fil.filename, c1);
			strcat(fil.filename, fil.fileType);
		}
	}
	if (find_file && (ntohl(th->th_ack) == fil.ack)){
		if (fil.seg == 0 && ntohs(ih->tlen) != 40){//write file
			fil.seg++;
			fp_file = fopen(fil.filename, "ab");//open image file, prepare to write image
			int temp = 0;
			for (; temp < http_len - 4; temp++){//coculate file size
				if (fil.allSize != 0){
					break;
				}
				if ((temp + 16 < http_len && strncmp(http_pkt_data + temp, "Content-Length: ", strlen("Content-Length: ")) == 0)){
					temp = temp + 16;
					int index = 0;
					char temp_char[20];
					for (; temp < http_len; temp++){
						if ((int)(http_pkt_data[temp]) == 13 && (int)(http_pkt_data[temp + 1]) == 10){
							fil.allSize = atoi(temp_char);
							break;
						}
						temp_char[index++] = http_pkt_data[temp];
					}
				}
			}
			for (; temp < http_len - 4; temp++){ //write file
				if ((int)(http_pkt_data[temp]) == 13 && (int)(http_pkt_data[temp + 1]) == 10 &&
					(int)(http_pkt_data[temp + 2]) == 13 && (int)(http_pkt_data[temp + 3]) == 10){ // http request form
					temp = temp + 4;
					break;
				}
			}
			for (; temp < http_len; temp++){
				fprintf(fp_file, "%c", http_pkt_data[temp]);
				fil.size++;
			}
		}
		else if (fil.seg != 0){
			fil.seg++;
			int temp = 0;
			for (; temp < http_len; temp++){
				fprintf(fp_file, "%c", http_pkt_data[temp]);
				fil.size++;
			}
		}
		if (ntohs(th->th_len_resv_code) == 20504 && (fil.size == fil.allSize && fil.size != 0)){
			fclose(fp_file);
			int temp = 0;
			num_file++;
			QString fileName,fileType;
			for (int i = 0; i < strlen(fil.filename); i++){
				fileName.append(fil.filename[i]);
			}
			for (int i = 0; i < strlen(fil.fileType); i++){
				fileType.append(fil.fileType[i]);
			}
			ui.tableWidgetFile->setRowCount(num_file);
			ui.tableWidgetFile->setItem(num_file - 1, temp++, new QTableWidgetItem(fileName));
			ui.tableWidgetFile->setItem(num_file - 1, temp++, new QTableWidgetItem(fileType));
			ui.tableWidgetFile->setItem(num_file - 1, temp++, new QTableWidgetItem(getSIp(ih)));
			ui.tableWidgetFile->setItem(num_file - 1, temp++, new QTableWidgetItem(QString::number(ntohs(th->th_sport))));
			ui.tableWidgetFile->setItem(num_file - 1, temp++, new QTableWidgetItem(getDIp(ih)));
			ui.tableWidgetFile->setItem(num_file - 1, temp++, new QTableWidgetItem(QString::number(ntohs(th->th_dport))));
			ui.tableWidgetFile->setItem(num_file - 1, temp++, new QTableWidgetItem(QString::number(fil.size)));
			find_file = false;
			fil.allSize = 0; fil.size = 0; fil.seg = 0;
			fil.writing = false;
			memset(fil.filename, 0, sizeof(fil.filename));
			memset(fil.fileType, 0, sizeof(fil.fileType));
		}
	}



}

void qt_demo::udpProcessor(ip_header * ih, udp_header * uh){
	num_udp++;
	ui.tableWidgetUdp->setRowCount(num_udp);
	int temp = 0;
	ui.tableWidgetUdp->setItem(num_udp - 1, temp++, new QTableWidgetItem(getSIp(ih)));
	ui.tableWidgetUdp->setItem(num_udp - 1, temp++, new QTableWidgetItem(QString::number(ntohs(uh->uh_sport))));
	ui.tableWidgetUdp->setItem(num_udp - 1, temp++, new QTableWidgetItem(getDIp(ih)));
	ui.tableWidgetUdp->setItem(num_udp - 1, temp++, new QTableWidgetItem(QString::number(ntohs(uh->uh_dport))));
	ui.tableWidgetUdp->setItem(num_udp - 1, temp++, new QTableWidgetItem(QString::number(ntohs(uh->uh_len))));
	ui.tableWidgetUdp->setItem(num_udp - 1, temp++, new QTableWidgetItem(QString::number(ntohs(uh->uh_sum))));
}

void qt_demo::icmpProcessor(ip_header * ih, icmp_header * icmp_h){
	num_icmp++;
	int temp = 0;
	ui.tableWidgetIcmp->setRowCount(num_icmp);
	ui.tableWidgetIcmp->setItem(num_icmp - 1, temp++, new QTableWidgetItem(getSIp(ih)));
	ui.tableWidgetIcmp->setItem(num_icmp - 1, temp++, new QTableWidgetItem(getDIp(ih)));
	ui.tableWidgetIcmp->setItem(num_icmp - 1, temp++, new QTableWidgetItem(QString::number(icmp_h->icmp_type)));
	ui.tableWidgetIcmp->setItem(num_icmp - 1, temp++, new QTableWidgetItem(QString::number(icmp_h->icmp_code)));
}


void qt_demo::clearAllWidget(){ //clear all tableWidget data
	ui.tableWidgetIcmp->clearContents();
	ui.tableWidgetHttp->clearContents();
	ui.tableWidgetTcp->clearContents();
	ui.tableWidgetUdp->clearContents();
	ui.tableWidgetIp->clearContents();
	ui.tableWidgetArp->clearContents();
	ui.tableWidgetImage->clearContents();
	ui.tableWidgetFile->clearContents();

	ui.tableWidgetIcmp->setRowCount(0);
	ui.tableWidgetHttp->setRowCount(0);
	ui.tableWidgetTcp->setRowCount(0);
	ui.tableWidgetUdp->setRowCount(0);
	ui.tableWidgetIp->setRowCount(0);
	ui.tableWidgetArp->setRowCount(0);
	ui.tableWidgetImage->setRowCount(0);
	ui.tableWidgetFile->setRowCount(0);

	num_arp = 0; num_ip = 0; num_icmp = 0; num_udp = 0; num_tcp = 0; num_http = 0; num_image = 0; num_file = 0; packetNum = 0;
}

QString qt_demo::getSMac(arp_header *ah){
	QString smac;
	return smac.sprintf("%x:%x:%x:%x:%x:%x", ah->ether_shost[0], ah->ether_shost[1], ah->ether_shost[2], ah->ether_shost[3], ah->ether_shost[4], ah->ether_shost[5]);
}

QString qt_demo::getDMac(arp_header *ah){
	QString dmac;
	return dmac.sprintf("%x:%x:%x:%x:%x:%x", ah->ether_dhost[0], ah->ether_dhost[1], ah->ether_dhost[2], ah->ether_dhost[3], ah->ether_dhost[4], ah->ether_dhost[5]);
}

QString qt_demo::getArpSIp(arp_header * ah){
	QString sip;
	return sip.sprintf("%d.%d.%d.%d", ah->saddr.byte1, ah->saddr.byte2, ah->saddr.byte3, ah->saddr.byte4);
}

QString qt_demo::getArpDIp(arp_header * ah){
	QString dip;

	return dip.sprintf("%d.%d.%d.%d", ah->daddr.byte1, ah->daddr.byte2, ah->daddr.byte3, ah->daddr.byte4);
}

QString qt_demo::getSIp(ip_header * ih){
	QString sip;
	return sip.sprintf("%d.%d.%d.%d", ih->saddr.byte1, ih->saddr.byte2, ih->saddr.byte3, ih->saddr.byte4);
}

QString qt_demo::getDIp(ip_header * ih){
	QString dip;
	return dip.sprintf("%d.%d.%d.%d", ih->daddr.byte1, ih->daddr.byte2, ih->daddr.byte3, ih->daddr.byte4);
}

QString qt_demo::getSipPTcp(ip_header * ih, tcp_header * th){
	QString sipP;
	return sipP.sprintf("%d.%d.%d.%d:%d", ih->saddr.byte1, ih->saddr.byte2, ih->saddr.byte3, ih->saddr.byte4, ntohs(th->th_sport));
}

QString qt_demo::getDipPTcp(ip_header * ih, tcp_header * th){
	QString dipP;
	return dipP.sprintf("%d.%d.%d.%d:%d", ih->daddr.byte1, ih->daddr.byte2, ih->daddr.byte3, ih->daddr.byte4, ntohs(th->th_dport));
}

QString qt_demo::getSipPUdp(ip_header * ih, udp_header * uh){
	QString sipP;
	return sipP.sprintf("%d.%d.%d.%d:%d", ih->saddr.byte1, ih->saddr.byte2, ih->saddr.byte3, ih->saddr.byte4, ntohs(uh->uh_sport));
}

QString qt_demo::getDipPUdp(ip_header * ih, udp_header * uh){
	QString dipP;
	return dipP.sprintf("%d.%d.%d.%d:%d", ih->daddr.byte1, ih->daddr.byte2, ih->daddr.byte3, ih->daddr.byte4, ntohs(uh->uh_dport));
}

