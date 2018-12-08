#include "QLanguage.h"
#include <QHBoxLayout>
#include <QTranslator>

QLanguageTest1::QLanguageTest1(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	m_pTranslator = new QTranslator(this);

	m_pLanguageCombo = new QComboBox(this);
	m_pLanguageLabel = new QLabel(this);

	QHBoxLayout *pLayout = new QHBoxLayout(this);
	pLayout->addWidget(m_pLanguageLabel);
	pLayout->addWidget(m_pLanguageCombo);
	//pLayout->addStretch(1);

	m_pLanguageCombo->addItem(QObject::tr("Chinese"));
	m_pLanguageCombo->addItem(QObject::tr("English"));
	m_pLanguageCombo->addItem(QObject::tr("Japanese"));

	//Ä¬ÈÏÏµÍ³ÓïÑÔ
	QLocale::Language eLangType = QLocale::system().language();
	switch (eLangType)
	{
	case QLocale::Chinese:
		m_pLanguageCombo->setCurrentIndex(LT_CHINESE);
		changeLanguage(LT_CHINESE);
		break;

	case QLocale::English:
		m_pLanguageCombo->setCurrentIndex(LT_ENGLISH);
		changeLanguage(LT_ENGLISH);
		break;

	case QLocale::Japanese:
		m_pLanguageCombo->setCurrentIndex(LT_JAPANESE);
		changeLanguage(LT_JAPANESE);
		break;

	default:
		break;
	}

	reTranslateUi();

	void (QComboBox::*pSignal)(int) = &QComboBox::currentIndexChanged;
	connect(m_pLanguageCombo, pSignal, [&](int index) {this->changeLanguage(index); });
}

void QLanguageTest1::changeEvent(QEvent * e)
{
	__super::changeEvent(e);

	switch (e->type())
	{
	case QEvent::LanguageChange:
		reTranslateUi();
		break;

	default:
		break;
	}
}

void QLanguageTest1::reTranslateUi()
{
	m_pLanguageLabel->setText(QObject::tr("Language"));
	m_pLanguageCombo->setItemText(LT_CHINESE, QObject::tr("Chinese"));
	m_pLanguageCombo->setItemText(LT_ENGLISH, QObject::tr("English"));
	m_pLanguageCombo->setItemText(LT_JAPANESE, QObject::tr("Japanese"));
}

void QLanguageTest1::changeLanguage(int nIndex)
{
	switch (nIndex)
	{
	case LT_CHINESE:
		m_pTranslator->load(":/QLanguageTest1/qlanguagetest1_zh.qm");
		break;

	case LT_ENGLISH:
		m_pTranslator->load(":/QLanguageTest1/qlanguagetest1_en.qm");
		break;

	case LT_JAPANESE:
		m_pTranslator->load(":/QLanguageTest1/qlanguagetest1_ja.qm");
		break;

	default:
		return;
		break;
	}

	qApp->installTranslator(m_pTranslator);
}
