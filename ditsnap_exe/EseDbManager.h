#pragma once
#include "Interfaces.h"

// Defined in EseDataAccess.h 
namespace EseDataAccess
{
	class EseTable;
	class EseDatabase;
	class EseInstance;
}

class EseDbManager :public ITableObservable, IDbObservable
{
public:
	EseDbManager();
	~EseDbManager();

	virtual void RegisterTableObserver(ITableObserver* o) override;
	virtual void RemoveTableObserver(ITableObserver* o) override;
	virtual void NotifyTableObservers() override;
	virtual void RegisterDbObserver(IDbObserver* o) override;
	virtual void RemoveDbObserver(IDbObserver* o) override;
	virtual void NotifyDbObservers() override;
	void OpenFile(wstring path);
	wstring GetFilePath() const;
	void SetTable(wstring name);
	wstring GetCurrentTableName() const;
	vector<wstring> GetTableNames() const;
	void MoveFirstRecord() const;
	BOOL MoveNextRecord() const;
	void Move(uint rowIndex) const;
	wstring RetrieveColumnDataAsString(uint columnIndex, uint itagSequence = 1) const;
	uint GetColumnCount() const;
	wstring GetColumnName(uint columnIndex) const;
	int CountColumnValue(uint columnIndex) const;

private:
	list<ITableObserver*> tableObservers_;
	list<IDbObserver*> tableNameObservers_;
	EseDataAccess::EseInstance* eseInstance_;
	EseDataAccess::EseDatabase* eseDatabase_;
	EseDataAccess::EseTable* eseTable_;
	wstring filePath_;
	vector<wstring> tableNames_;
	wstring currentTableName_;

	void CleanupEse();

	DISALLOW_COPY_AND_ASSIGN(EseDbManager);
};
