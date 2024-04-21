// DataProvider.h
#ifndef DATAPROVIDER_H
#define DATAPROVIDER_H

#include <QObject>
#include <QTimer>
#include <string>

class DataProvider : public QObject {
  Q_OBJECT
  Q_PROPERTY(int dataValue READ dataValue NOTIFY dataValueChanged)
  Q_PROPERTY(int ericTest READ ericTest NOTIFY ericTestChanged)
  Q_PROPERTY(int doubleValue READ doubleValue NOTIFY doubleValueChanged)

public:
  explicit DataProvider(QObject *parent = nullptr);

  int dataValue() const;
  int ericTest() const;
  double doubleValue() const;

signals:
  void dataValueChanged(int newValue);
  void ericTestChanged(int newValue);
  void doubleValueChanged(double newValue);

public slots:
  void updateData(); // Slot to update data from a device or simulation

private:
  int dataValue_;
  double doubleValue_;
  int ericTest_;
  bool increment_;
  std::string displayLiters_;
  QTimer m_timer;
};

#endif // DATAPROVIDER_H
