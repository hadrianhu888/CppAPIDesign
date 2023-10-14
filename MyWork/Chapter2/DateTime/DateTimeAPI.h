#pragma once

#ifndef DATE_TIME_API_H
#define DATE_TIME_API_H

class Year {
public:
  Year(int year);
  bool isLeap() const;

private:
  int year_;
  bool leap_;
};

class Month {
public:
  Month(const Year &year, int month);
  int getDays() const;

private:
  int month_;
  int days_;
};

class Day {
public:
  Day(int day);

private:
  int day_;
};

class Date {
public:
  Date(int year, int month, int day);
  ~Date();
  void print() const;

private:
  Year *year_;
  Month *month_;
  Day *day_;
};

class Time1 : public Date {
public:
  Time1(int year, int month, int day, int hour, int minute, int second);
  void print() const;

private:
  int hour_;
  int minute_;
  int second_;
};

#endif // DATE_TIME_API_H
