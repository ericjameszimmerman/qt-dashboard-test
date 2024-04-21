// DataProvider.cpp
#include "dataProvider.h"
#include <iomanip>
#include <iostream>
#include <random>
#include <sstream> // For std::ostringstream

DataProvider::DataProvider(QObject *parent)
    : QObject(parent), dataValue_(0), ericTest_(0), increment_(false) {
  connect(&m_timer, &QTimer::timeout, this, &DataProvider::updateData);
  m_timer.start(50); // Update data every second
}

int DataProvider::dataValue() const { return dataValue_; }

int DataProvider::ericTest() const { return ericTest_; }

double DataProvider::doubleValue() const { return doubleValue_; }

/*
void setDisplayLiters(double litersDisplayCount) {
  std::ostringstream stream;
  stream << std::fixed << std::setprecision(1) << (litersDisplayCount / 10.0);
  displayLiters_ = stream.str();
}
*/

void DataProvider::updateData() {
  // Simulate data or read from device
  std::random_device rd;
  std::mt19937 gen(rd());

  /*
  std::uniform_int_distribution<> distrib(1, 100);

  int newValue = distrib(gen); // Randomly generated value for simulation
  if (dataValue_ != newValue) {
    dataValue_ = newValue;
    emit dataValueChanged(newValue);
  }
  */

  if (ericTest_ <= 0) {
    increment_ = true;
    ericTest_++;
  } else if (ericTest_ >= 11000) {
    increment_ = false;
    ericTest_--;

  } else if (increment_) {
    ericTest_++;
  } else {
    ericTest_--;
  }

  doubleValue_ = ericTest_;
  dataValue_ = ericTest_;

  emit ericTestChanged(ericTest_);
  emit doubleValueChanged(doubleValue_);
  emit dataValueChanged(dataValue_);
}
