#include "AIV_JDZ.h"

AIV_JDZ::AIV_JDZ(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	ui.Gpg_saveBtn->setEnabled(false);
	ui.Cbg_saveBtn->setEnabled(false);
	ui.Ppg_saveBtn->setEnabled(false);
}

//void AIV_JDZ::GetPara() {
//		gpgInitial();
//		cbgInitial();
//		//qDebug() << ui.with_dark->isChecked();
//		
//}
void AIV_JDZ::gpgInitial() {
	gpgPara[0] = ui.Gpg_Pattern_number->text().toInt();
	gpgPara[1] = ui.Gpg_Code_lines->text().toInt();
	gpgPara[2] = ui.Gpg_Image_rows->text().toInt();
	gpgPara[3] = ui.Gpg_Image_cols->text().toInt();
	gpgPara[4] = ui.Gpg_Pattern_lstrow->text().toInt();
	gpgPara[5] = ui.Gpg_Pattern_lstcol->text().toInt();
	gpgPara[6] = ui.Gpg_Pattern_rows->text().toInt();
	gpgPara[7] = ui.Gpg_Pattern_cols->text().toInt();
	gpgPara[8] = ui.Gpg_Mark_lstrow->text().toInt();
	gpgPara[9] = ui.Gpg_Mark_lstcol->text().toInt();
	gpgPara[10] = ui.Gpg_Mark_rows->text().toInt();
	gpgPara[11] = ui.Gpg_Mark_cols->text().toInt();
	gpgPara[12] = ui.Gpg_with_dark->isChecked();
}
void AIV_JDZ::cbgInitial() {
	cbgPara[0] = ui.Cbg_Image_rows->text().toInt();
	cbgPara[1] = ui.Cbg_Image_cols->text().toInt();
	cbgPara[2] = ui.Cbg_Chess_lstrow->text().toInt();
	cbgPara[3] = ui.Cbg_Chess_lstcol->text().toInt();
	cbgPara[4] = ui.Cbg_Edge_rows->text().toInt();
	cbgPara[5] = ui.Cbg_Edge_cols->text().toInt();
	cbgPara[6] = ui.Cbg_Corner_rows->text().toInt();
	cbgPara[7] = ui.Cbg_Corner_cols->text().toInt();
	cbgPara[8] = ui.Cbg_Mark_lstrow->text().toInt();
	cbgPara[9] = ui.Cbg_Mark_lstcol->text().toInt();
	cbgPara[10] = ui.Cbg_Mark_rows->text().toInt();
	cbgPara[11] = ui.Cbg_Mark_cols->text().toInt();
}

void AIV_JDZ::ppgInitial() {
	ppgPara[0] = ui.Ppg_Image_number->text().toInt();
	ppgPara[1] = ui.Ppg_Image_rows->text().toInt();
	ppgPara[2] = ui.Ppg_Image_cols->text().toInt();
	ppgPara[3] = ui.Ppg_Pattern_lstrow->text().toInt();
	ppgPara[4] = ui.Ppg_Pattern_lstcol->text().toInt();
	ppgPara[5] = ui.Ppg_Pattern_rows->text().toInt();
	ppgPara[6] = ui.Ppg_Pattern_cols->text().toInt();
	ppgPara[7] = ui.Ppg_peiod_lines->text().toInt();
	ppgPara[8] = ui.Ppg_Mark_lstrow->text().toInt();
	ppgPara[9] = ui.Ppg_Mark_lstcol->text().toInt();
	ppgPara[10] = ui.Ppg_Mark_rows->text().toInt();
	ppgPara[11] = ui.Ppg_Mark_cols->text().toInt();
	qDebug() << ppgPara[11];
	ppgPara[12] = ui.Ppg_with_mark->isChecked();
	ppgPara_OPS = ui.PPg_OriginalPhaseShift->text().toFloat();
}

void AIV_JDZ::on_Gpg_generateBtn_clicked() {
	gpgInitial();
	Gpg_generateImage();
	ui.Gpg_saveBtn->setEnabled(true);
}
void AIV_JDZ::on_Cbg_generateBtn_clicked() {
	qDebug() << 1;
	cbgInitial();
	Cbg_generateImage();
	ui.Cbg_saveBtn->setEnabled(true);
}
void AIV_JDZ::on_Ppg_generateBtn_clicked() {
	ppgInitial();
	Ppg_generateImage();
	ui.Ppg_saveBtn->setEnabled(true);
}

void AIV_JDZ::on_Gpg_saveBtn_clicked() {
	 Gpg_dirPath = QFileDialog::getExistingDirectory(this, tr("Save Path..."), "./", QFileDialog::ShowDirsOnly);
	 Gpg_saveImage();
}
void AIV_JDZ::on_Cbg_saveBtn_clicked() {
	Cbg_dirPath = QFileDialog::getExistingDirectory(this, tr("Save Path..."), "./", QFileDialog::ShowDirsOnly);
	Cbg_saveImage();
}
void AIV_JDZ::on_Ppg_saveBtn_clicked() {
	Ppg_dirPath = QFileDialog::getExistingDirectory(this, tr("Save Path..."), "./", QFileDialog::ShowDirsOnly);
	Ppg_saveImage();
}

void AIV_JDZ::Gpg_generateImage() {   //生成Gpg图片
	AIV_GreyPatternGenerator gpg(gpgPara);
	gpgImages = gpg.gpgImages;
}
void AIV_JDZ::Cbg_generateImage() {    //生成Cbg图片
	AIV_ChessBoardGenerator cbg(cbgPara);
	cbgImages = cbg.cbgImages;
}
void AIV_JDZ::Ppg_generateImage() {
	AIV_PhasePatternGenerator ppg(ppgPara, ppgPara_OPS);
	ppgImages = ppg.ppgImages;
}

void AIV_JDZ::Gpg_saveImage() {
	string str = Gpg_dirPath.toStdString();
	QDateTime datetime;
	String timestr = datetime.currentDateTime().toString("MM-dd-HH-mm-ss").toStdString();
	for (int i = 0; i < gpgImages.size(); ++i) {
		imwrite(str + "/" + timestr+"_Gpgimg"+ to_string(i) +".bmp", gpgImages[i]);
	}
}
void AIV_JDZ::Cbg_saveImage() {
	string str = Cbg_dirPath.toStdString();
	QDateTime datetime;
	String timestr = datetime.currentDateTime().toString("MM-dd-HH-mm-ss").toStdString();
	for (int i = 0; i < cbgImages.size(); ++i) {
		imwrite(str + "/" + timestr + "_Cbgimg" + to_string(i) + ".bmp", cbgImages[i]);
	}
}
void AIV_JDZ::Ppg_saveImage() {
	string str = Ppg_dirPath.toStdString();
	QDateTime datetime;
	String timestr = datetime.currentDateTime().toString("MM-dd-HH-mm-ss").toStdString();
	for (int i = 0; i < ppgImages.size(); ++i) {
		imwrite(str + "/" + timestr + "_PPgimg" + to_string(i) + ".bmp", ppgImages[i]);
	}
}
