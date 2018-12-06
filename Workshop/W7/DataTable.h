/*
Name: Suganya  Maheswaran
email: smaheswaran4@seneca.ca
student: 048298137
date: Nov 08 2018
*/
#ifndef W7_DATATABLE_H
#define W7_DATATABLE_H

#include <fstream>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <math.h>
#include<functional>
#include <numeric>
#include <vector>

namespace w7
{

	template <typename T>
	class DataTable
	{
		int m_width;
		int m_precision;

		std::vector<T> m_x = std::vector<T>();
		std::vector<T> m_y = std::vector<T>();

	public:
		DataTable(std::ifstream &file, int width, int percision)
		{
			T x, y;
			
				while(file >> x >> y)
				{
					if (x != ' ' && y != ' ')
					{
						m_x.push_back(x);
						m_y.push_back(y);
					}
			}
			m_width = width;
			m_precision = percision;
		}

		T mean() const
		{
			return std::accumulate(m_y.begin(), m_y.end(), (T)0) / m_y.size();
		}

		T sigma() const
		{
			T temp_mean = mean();
			std::vector<T> diff(m_y.size());
			std::transform(m_y.begin(), m_y.end(), diff.begin(),
				std::bind2nd(std::minus<T>(), temp_mean));
			T sum = std::inner_product(diff.begin(), diff.end(), diff.begin(), (T)0);
			
			return sqrt(sum / (m_y.size() - 1));
		
	//		T sum = 0; 
		//	for (int i = 0; i < m_x.size(); i++)
	//		{
	//			sum+= sqrt((m_y[i] - mean ), 2)
		//	}
			//T index = sum/ m_x.size()-1
		}

		T median() const
		{
			std::vector<T> temp = m_y;
			sort(temp.begin(), temp.end());
			T index = temp[temp.size() / 2];
			return index; 
		}

		void regression(T &slope, T &y_intercept) const
		{
			const auto n = m_x.size();
			const auto s_x = std::accumulate(m_x.begin(), m_x.end(), 0.0);
			const auto s_y = std::accumulate(m_y.begin(), m_y.end(), 0.0);
			const auto s_xx = std::inner_product(m_x.begin(), m_x.end(), m_x.begin(), 0.0);
			const auto s_xy = std::inner_product(m_x.begin(), m_x.end(), m_y.begin(), 0.0);
			slope = (n * s_xy - s_x * s_y) / (n * s_xx - s_x * s_x);
			y_intercept = (s_y - slope * s_x) / n;
		}

		void display(std::ostream &os) const
		{
			os << std::fixed << std::setw(m_width) << "x" << std::setw(m_width) << "y" << std::endl;
			for (int i = 0; i < m_x.size(); ++i)
				os << std::fixed << std::setw(m_width) << 
				std::setprecision(m_precision) << m_x[i] 
				<< std::setprecision(m_precision) <<std::setw(m_width) << m_y[i] << std::endl;
			
		}

		size_t getSize() const
		{
			return m_x.size();
		}
	};

	template <typename T>
	std::ostream &operator<<(std::ostream &os, const DataTable<T> &table)
	{
		table.display(os);
		return os;
	}

} // namespace w7

#endif