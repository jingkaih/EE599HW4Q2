#include "solution.h"

void MaxHeap::TrickleUp(int i)
{
  while(i != 0)
  {
    if(data_[i] > data_[(i - 1) / 2])
    {
      std::iter_swap(data_.begin() + i, data_.begin() + (i - 1) / 2);
    }
    else
    {
      break;
    }
    i = (i - 1) / 2;
  }
}

void MaxHeap::TrickleDown(int i)
{
  while(i * 2 + 1 < data_.size())
  {
    if(i * 2 + 1 == data_.size() - 1)//only has one child, last round
    {
      if(data_[i] < data_[i*2+1])
      {
        std::iter_swap(data_.begin() + i, data_.begin() + (i*2+1));
        break;
      }
      else
      {
        break;
      }
    }
    else//has two children
    {
      if((data_[i] < data_[i*2+1]) && (data_[i] < data_[i*2+2]))
      {
        if(data_[i*2+1] > data_[i*2+2])
        {
          std::iter_swap(data_.begin() + i, data_.begin() + (i*2+1));
          i = i*2+1;
        }
        else
        {
          std::iter_swap(data_.begin() + i, data_.begin() + (i*2+2));
          i = i*2+2;
        }
      }
      else if ((data_[i] < data_[i*2+1]) && (data_[i] > data_[i*2+2]))
      {
        std::iter_swap(data_.begin() + i, data_.begin() + (i*2+1));
        i = i*2+1;
      }
      else if ((data_[i] > data_[i*2+1]) && (data_[i] < data_[i*2+2]))
      {
        std::iter_swap(data_.begin() + i, data_.begin() + (i*2+2));
        i = i*2+2;
      }
      else
      {
        break;
      }
 
    }
  }
}

void MaxHeap::push(int v)
{
  data_.push_back(v);
  idx++;
  if(idx > 0)
  {
    int i = idx;
    TrickleUp(i);
  }
}

void MaxHeap::pop()
{
  *data_.begin() = *(data_.begin() + data_.size() - 1);
  data_.pop_back();
  TrickleDown(0);
}

int MaxHeap::GetParentIndex(int i)
{
  int j = (i != 0)?(i-1)/2 : -1; 
  return j;
}

int MaxHeap::GetLeftIndex(int i)
{
  int j = ((i*2 + 1 < data_.size())? i*2 + 1: -1);
  return j;
}

int MaxHeap::GetRightIndex(int i)
{
  int j = ((i*2 + 2 < data_.size())? i*2 + 2: -1);
  return j;
}

int MaxHeap::GetLargestChildIndex(int i)
{
  if(i * 2 + 1 == data_.size() - 1)
  {
    return i*2+1;
  }
  else if(i * 2 + 1 > data_.size() -1)
  {
    return -1;
  }
  else
  {
    if(data_[i*2+1] > data_[i*2+2])
    return i*2+1;
    else
    return i*2+2;
  }
  
}

int MaxHeap::GetLeft(int i)
{
  int j = GetLeftIndex(i);
  int left = (j != -1)?data_[j] : INT16_MAX;
  return left;
}

int MaxHeap::GetRight(int i)
{
  int j = GetRightIndex(i);
  int right = (j != -1)?data_[j] : INT16_MAX;
  return right;
}

int MaxHeap::GetParent(int i)
{
  int parent = (i != 0)?data_[(i-1)/2] : INT16_MAX;
  return parent;
}

int MaxHeap::top()
{
  return data_[0];
}