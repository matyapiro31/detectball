/*
 * main.cpp
 * Copyright (C) 2015 akira <akira@akira-desktop>
 * 
 * detectball is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * detectball is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

int main(int argc,char **argv)
{
	if(argc==1){
		std::cerr << "The argument is not given!" << std::endl;
	}
	cv::Mat m1,m2,m3;
	m1=cv::imread(argv[1],1);
	m2=cv::imread(argv[1],1);
	m3=m1.clone();
	cv::GaussianBlur(m2,m2,cv::Size(11,11),2,2);
	cv::cvtColor(m2,m2,CV_BGR2GRAY);
	std::vector<cv::Vec3f> circles;
	cv::HoughCircles(m2,circles,CV_HOUGH_GRADIENT,1,100,20,50);
	if(!circles.size()){
		return 0;
	}
	int max=circles.size();
	for(int i=0;i<max;i++){
		cv::Point center(cv::saturate_cast<int>(circles[i][0]),
			cv::saturate_cast<int>(circles[i][1])
		);
		int radius=cv::saturate_cast<int>(circles[i][2]);
		cv::circle(m3,center,radius,cv::Scalar(0,0,255),2);
	}
	cv::namedWindow("Source Image",CV_WINDOW_AUTOSIZE|CV_WINDOW_FREERATIO);
	cv::imshow("Source Image",m1);
	cv::namedWindow("Destination Image",CV_WINDOW_AUTOSIZE|CV_WINDOW_FREERATIO);
	cv::imshow("Destination Image",m3);
	cv::imwrite("ad.jpg",m3);
	cv::waitKey(0);
	return 0;
}

