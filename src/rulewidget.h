// Copyright (C) 2013 July IGHOR.
// I want to create trading application that can be configured for any rule and strategy.
// If you want to help me please Donate: 1d6iMwjjNo8ZGYeJBZKXgcgVk9o7fXcjc
// For any questions please use contact form https://sourceforge.net/projects/bitcointrader/
// Or send e-mail directly to julyighor@gmail.com
//
// You may use, distribute and copy the Qt Bitcion Trader under the terms of
// GNU General Public License version 3

#ifndef RULEWIDGET_H
#define RULEWIDGET_H

#include <QWidget>
#include "ui_rulewidget.h"
#include "rulesmodel.h"
#include <QTime>

class RuleWidget : public QWidget
{
	Q_OBJECT

public:
	void saveRulesData();
	bool haveWorkingRules();
	bool haveAnyRules();
	void removeGroup();
	void languageChanged();
	void checkAndExecuteRule(int ruleType, double price);
	Ui::RuleWidget ui;
	RulesModel *rulesModel;
	RuleWidget(QString groupName, RuleWidget *copyFrom=0);
	~RuleWidget();

private:
	QTime ordersCancelTime;
	QMenu *rulesEnableDisableMenu;
	QString groupName;
private slots:
	void on_ruleUp_clicked();
	void on_ruleDown_clicked();
	void rulesMenuRequested(const QPoint&);
	void ruleDisableEnableMenuFix();
	void on_ruleConcurrentMode_toggled(bool);
	void ruleEnableSelected();
	void ruleDisableSelected();
	void ruleEnableAll();
	void ruleDisableAll();
	void on_ruleAddButton_clicked();
	void on_ruleEditButton_clicked();
	void on_ruleRemoveAll_clicked();
	void checkValidRulesButtons();
	void on_ruleRemove_clicked();
};

#endif // RULEWIDGET_H
