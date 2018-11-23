#include<iostream>
#include<opencv2/opencv.hpp>
#include<cmath>
#include<string.h>
#include<vector>
#include<dirent.h>
#include<mysql/mysql.h>

using namespace std;
using namespace cv;

void body_seg(string src);
void calcu_hist(Mat src_image,int dime,int hist[],int start_row,int start_col,int end_row,int end_col,int patch,int small_value,int big_value);
void draw_hist(int hist_array[],string img_name);
double calcu_distance(int hist1[],int hist2[]);
vector<string> get_filename_in_direct(string path);
double distance_between_two_img(string src_img,string test_img);
double accuracy_test(string path_input,string path_test);
vector<string> get_topn(string img_id,string dir_path,int topn);
void insert_data2database(vector<string> row);
vector<string> get_record_from_database(int position,string cameraid);



int main()
{
  vector<string> result = get_record_from_database(800,"secon");
  for(int i=0;i<result.size();i=i+1)
    cout<<result[i]<<endl;


  // vector<string> img_list = get_filename_in_direct("./images_position");
  // vector<string> topn;
  // int i;
  // int length = img_list.size();
  // string absolute_img;
  // for(i=0;i<length;i=i+1)
  // {
  //   absolute_img = "./images_position/"+img_list[i];
  //   topn = get_topn(absolute_img,"./images_position",5);
  //   insert_data2database(topn);
  // }



  // vector<string> row;
	// row.push_back("aa");
	// row.push_back("bb");
	// row.push_back("cc");
	// row.push_back("dd");
	// row.push_back("dh");
	// row.push_back("last");
	// insert_data2database(row);

  // vector<string> result;
  // result = get_topn("/home/ansheng/Desktop/colorspace/real_photos/input/xd_3_1.PNG","/home/ansheng/Desktop/colorspace/real_photos/output",4);
  // int i = 0;
  // for(i=0;i<result.size();i=i+1)
  // {
  //   cout<<result[i]<<endl;
  // }
  // double acc = accuracy_test("/home/ansheng/Desktop/real_photos/input","/home/ansheng/Desktop/real_photos/output");
  // cout<<acc<<endl;
  // string src="body/2.jpg";
  // int init_hist[300];
  // int hist1[300],hist2[300];
  //
  // Mat img = imread(src);
  // Mat hsv;
  // int row_num = img.rows;
  // int col_num = img.cols;
  // int start_row,start_col,end_row,end_col;
  // start_row = int(0.19*row_num);
  // start_col = int(0.1*col_num);
  // end_row = int(0.5*row_num);
  // end_col = int(0.9*col_num);
  //
  // cvtColor(img,hsv,CV_BGR2HSV);
  // calcu_hist(hsv,0,init_hist,start_row,start_col,end_row,end_col,10,0,180);
  // memcpy(hist1,init_hist,sizeof(init_hist));
  //
  // img = imread("body/3.jpg");
  // cvtColor(img,hsv,CV_BGR2HSV);
  // calcu_hist(hsv,0,init_hist,start_row,start_col,end_row,end_col,10,0,180);
  // memcpy(hist2,init_hist,sizeof(init_hist));
  //
  // double distance = calcu_distance(hist1,hist2);
  //
  // vector<string> filelist ;
  // cout<<accuracy_test("images/input","images/output")<<endl;
  // vector<string> bodyname;
  // bodyname = get_filename_in_direct("/home/ansheng/Desktop/qt/screenfromvideo/images");
  // int i;
  // string name;
  // for(i=0;i<bodyname.size();i=i+1)
  // {
  //   name = bodyname[i];
  //   name="/home/ansheng/Desktop/qt/screenfromvideo/images/"+name;
  //   body_seg(name);
  // }


  return 0;
}

void body_seg(string src)
{
  Mat img = imread(src);
  int width,height;
  width = img.rows;
  height = img.cols;
  int i,j,k;
  int row_1,row_2,row_3;
  row_1 = int(0.19*width);
  row_2 = int(0.5*width);
  row_3 = int(0.7*width);

  int body_1,body_2,leg_1,leg_2;
  body_1 = int(height*0.1);
  body_2 = int(height*0.9);

  leg_1 = int(height*0.15);
  leg_2 = int(height*0.85);


  for(i=row_1;i<row_1+4;i=i+1)
  {
    for(j=body_1;j<body_2;j=j+1)
    {
      img.at<cv::Vec3b>(i,j)[0]=255;
      img.at<cv::Vec3b>(i,j)[1]=0;
      img.at<cv::Vec3b>(i,j)[2]=0;
    }
  }

  for(i=row_2;i<row_2+4;i=i+1)
  {
    for(j=body_1;j<body_2;j=j+1)
    {
      img.at<cv::Vec3b>(i,j)[0]=255;
      img.at<cv::Vec3b>(i,j)[1]=0;
      img.at<cv::Vec3b>(i,j)[2]=0;
    }
  }

  for(i=row_3;i<row_3+4;i=i+1)
  {
    for(j=leg_1;j<leg_2;j=j+1)
    {
      img.at<cv::Vec3b>(i,j)[0]=255;
      img.at<cv::Vec3b>(i,j)[1]=0;
      img.at<cv::Vec3b>(i,j)[2]=0;
    }
  }

  for(i=row_1;i<row_2;i=i+1)
  {
    for(j=body_1;j<body_1+4;j=j+1)
    {
      img.at<cv::Vec3b>(i,j)[0]=255;
      img.at<cv::Vec3b>(i,j)[1]=0;
      img.at<cv::Vec3b>(i,j)[2]=0;
    }
  }

  for(i=row_1;i<row_2;i=i+1)
  {
    for(j=body_2;j<body_2+4;j=j+1)
    {
      img.at<cv::Vec3b>(i,j)[0]=255;
      img.at<cv::Vec3b>(i,j)[1]=0;
      img.at<cv::Vec3b>(i,j)[2]=0;
    }
  }

  for(i=row_2;i<row_3;i=i+1)
  {
    for(j=leg_1;j<leg_1+4;j=j+1)
    {
      img.at<cv::Vec3b>(i,j)[0]=255;
      img.at<cv::Vec3b>(i,j)[1]=0;
      img.at<cv::Vec3b>(i,j)[2]=0;
    }
  }

  for(i=row_2;i<row_3;i=i+1)
  {
    for(j=leg_2;j<leg_2+4;j=j+1)
    {
      img.at<cv::Vec3b>(i,j)[0]=255;
      img.at<cv::Vec3b>(i,j)[1]=0;
      img.at<cv::Vec3b>(i,j)[2]=0;
    }
  }
  imshow("boundary",img);
  waitKey(0);
}

void calcu_hist(Mat src_image,int dime,int hist[],int start_row,int start_col,int end_row,int end_col,int patch,int small_value,int big_value)
{
  memset(hist, 0, sizeof(int)*300);
  int allnumber = (big_value-small_value)/patch + 1;
  int value;
  hist[0] = allnumber;
  int i,j;
  for(i = start_row;i<end_row;i=i+1)
  {
    for(j=start_col;j<end_col;j=j+1)
    {
      value = int(src_image.at<Vec3b>(i,j)[dime]);
      if(value > (small_value-1) && value <(big_value+1) )
      {
        hist[(value-small_value)/patch+1] = hist[(value-small_value)/patch+1] + 1;
      }
    }
  }

}

void draw_hist(int hist_array[],string img_name)
{
  int color_num,index;
  color_num = hist_array[0];

  Mat hist_diagram = Mat::zeros(Size(color_num*5+100,600),CV_8UC3);
  cout<<hist_diagram.channels()<<endl;
  cout<<"start"<<endl;
  int i,j,k;
  for(i=1;i<(color_num+1);i=i+1)
  {
    cout<<"1for"<<endl;
    for(j=400-hist_array[i];j<400;j=j+1)
    {
      cout<<"2for"<<endl;
      for(k=50+i*5;k<50+(i+1)*5;k=k+1)
      {
        cout<<"3for"<<endl;
        if(0==i%2)
        {
          cout<<"ifstart"<<endl;
          hist_diagram.at<Vec3b>(j,k)[0]=255;
          cout<<"ddddd"<<endl;
        }
        else
        {
          cout<<"elsestart"<<endl;
          hist_diagram.at<Vec3b>(j,k)[1]=255;
          cout<<"else end"<<endl;
        }
      }
    }
  }
  cout<<img_name<<endl;
  imwrite(img_name,hist_diagram);
  imshow("empty",hist_diagram);
  waitKey(0);
}

double calcu_distance(int hist1[],int hist2[])
{
  double distance=0.0;
  int color_num = hist1[0];
  int sum_hist1=0,sum_hist2=0;
  int i;
  for(i=1;i<(color_num+1);i=i+1)
  {
    sum_hist1 = sum_hist1 + hist1[i];
    sum_hist2 = sum_hist2 + hist2[i];
  }

  double sqrt_sum = 0.0;
  for(i=1;i<(color_num+1);i=i+1)
  {
    sqrt_sum = sqrt_sum + sqrt(hist1[i]*hist2[i]);
  }
  distance = sqrt(abs(1-(sqrt_sum/sqrt((sum_hist1*sum_hist2)))));
  return distance;

}

vector<string> get_filename_in_direct(string path)
{
  struct dirent *ptr;
  DIR *dir;
  const char* PATH = path.c_str();
  dir = opendir(PATH);
  vector<string> files;
  while((ptr=readdir(dir))!=NULL)
  {
    if(ptr->d_name[0] == '.')
      continue;
    files.push_back(ptr->d_name);
  }
  return files;
}

double distance_between_two_img(string img_path1,string img_path2)
{
  double distance = 0.0;
  int init_hist[300];
  int hist1[300];
  int hist2[300];
  Mat img1,img2,hsv1,hsv2;
  img1 = imread(img_path1);
  img2 = imread(img_path2);
  cvtColor(img1,hsv1,CV_BGR2HSV);
  cvtColor(img2,hsv2,CV_BGR2HSV);
  int width,height;
  width = img1.cols;
  height = img1.rows;
  int col_start_body,col_end_body,col_start_leg,col_end_leg;
  col_start_body = int(0.1*width);
  col_end_body = int(0.9*width);
  col_start_leg = int(0.15*width);
  col_end_leg = int(0.85*width);
  int row_list[15];
  int i=0;
  for(i=0;i<5;i=i+1)
  {
    row_list[i] = int((0.19+i*0.06)*height);
  }
  for(i=0;i<6;i=i+1)
  {
    row_list[i+5] = int((0.5+i*0.04)*height );
  }
  for(i=0;i<5;i=i+1)
  {
    calcu_hist(hsv1,0,init_hist,row_list[i],col_start_body,row_list[i+1],col_end_body,10,0,180);
    memcpy(hist1,init_hist,sizeof(init_hist));
    calcu_hist(hsv2,0,init_hist,row_list[i],col_start_body,row_list[i+1],col_end_body,10,0,180);
    memcpy(hist2,init_hist,sizeof(init_hist));
    distance = distance + 0.5 * calcu_distance(hist1,hist2);

    calcu_hist(hsv1,1,init_hist,row_list[i],col_start_body,row_list[i+1],col_end_body,10,0,255);
    memcpy(hist1,init_hist,sizeof(init_hist));
    calcu_hist(hsv2,1,init_hist,row_list[i],col_start_body,row_list[i+1],col_end_body,10,0,255);
    memcpy(hist2,init_hist,sizeof(init_hist));
    distance = distance + 0.3 * calcu_distance(hist1,hist2);

    calcu_hist(hsv1,2,init_hist,row_list[i],col_start_body,row_list[i+1],col_end_body,10,0,255);
    memcpy(hist1,init_hist,sizeof(init_hist));
    calcu_hist(hsv2,2,init_hist,row_list[i],col_start_body,row_list[i+1],col_end_body,10,0,255);
    memcpy(hist2,init_hist,sizeof(init_hist));
    distance = distance + 0.2 * calcu_distance(hist1,hist2);
  }

  for(i=0;i<5;i=i+1)
  {
    calcu_hist(hsv1,0,init_hist,row_list[i+5],col_start_leg,row_list[i+6],col_end_leg,10,0,180);
    memcpy(hist1,init_hist,sizeof(init_hist));
    calcu_hist(hsv2,0,init_hist,row_list[i+5],col_start_leg,row_list[i+6],col_end_leg,10,0,180);
    memcpy(hist2,init_hist,sizeof(init_hist));
    distance = distance + 0.5 * calcu_distance(hist1,hist2);

    calcu_hist(hsv1,1,init_hist,row_list[i+5],col_start_leg,row_list[i+6],col_end_leg,10,0,255);
    memcpy(hist1,init_hist,sizeof(init_hist));
    calcu_hist(hsv2,1,init_hist,row_list[i+5],col_start_leg,row_list[i+6],col_end_leg,10,0,255);
    memcpy(hist2,init_hist,sizeof(init_hist));
    distance = distance + 0.3 * calcu_distance(hist1,hist2);

    calcu_hist(hsv1,2,init_hist,row_list[i+5],col_start_leg,row_list[i+6],col_end_leg,10,0,255);
    memcpy(hist1,init_hist,sizeof(init_hist));
    calcu_hist(hsv2,2,init_hist,row_list[i+5],col_start_leg,row_list[i+6],col_end_leg,10,0,255);
    memcpy(hist2,init_hist,sizeof(init_hist));
    distance = distance + 0.3 * calcu_distance(hist1,hist2);
  }
  return distance;
}

double accuracy_test(string path_input,string path_test)
{
  double accuracy = 0.0;
  vector<string> input_list;
  vector<string> test_list;

  input_list = get_filename_in_direct(path_input);
  test_list = get_filename_in_direct(path_test);
  int input_length = input_list.size();
  int test_length = test_list.size();
  int accuracy_number=0, test_number=input_length;
  int index_input,index_test;
  double distance_smallest,distance_temp;
  string img_test_temp,img_result;
  string person_input,person_result;
  string img_input;
  for(index_input = 0;index_input<input_length;index_input = index_input+1)
  {
    distance_smallest = 10.0;
    img_input = input_list[index_input];
    person_input = img_input.substr(0,img_input.find("_"));
    img_input = path_input + "/"+img_input;
    for(index_test=0;index_test<test_length;index_test = index_test+1)
    {
      img_test_temp = path_test +"/"+ test_list[index_test];
      distance_temp = distance_between_two_img(img_input,img_test_temp);
      if(distance_temp<distance_smallest)
      {
        distance_smallest = distance_temp;
        person_result = test_list[index_test];
      }
    }
    person_result = person_result.substr(0,person_result.find("_"));
    if(person_result == person_input)
    {
      accuracy_number = accuracy_number+1;
    }
    cout<<"intput:"<<person_input<<endl;
    cout<<"result:"<<person_result<<endl;
  }

  return (accuracy_number/(test_number*1.0));
}


vector<string> get_topn(string img_id,string dir_path,int topn)
{
  vector<string> result;
  string pure_img;
  vector<string> img_in_dir;
  img_in_dir = get_filename_in_direct(dir_path);
  pure_img = img_id.substr(img_id.find_last_of("/")+1,img_id.length());
  result.push_back(pure_img);
  int imgs_all_count = img_in_dir.size();
  double distance_list[imgs_all_count];
  int i,j;
  int index;
  double temp_distance;
  string absolute_path;

  for(i=0;i<imgs_all_count;i=i+1)
  {
    if(pure_img == img_in_dir[i])
    {
      distance_list[i] = 10.0;
    }
    else
    {
      absolute_path = dir_path+"/"+img_in_dir[i];
      distance_list[i] = distance_between_two_img(img_id,absolute_path);
    }
  }

  for(i=0;i<topn;i=i+1)
  {
    index = 0;
    temp_distance = distance_list[0];
    for(j=0;j<imgs_all_count;j=j+1)
    {
      if(distance_list[j]<temp_distance)
      {
        index = j;
        temp_distance = distance_list[index];
      }
    }
    result.push_back(img_in_dir[index]);
    distance_list[index] = 10.0;
  }
  return result;
}

void insert_data2database(vector<string> row)
{
	int count = row.size();
	int i;
	string value ="'" + row[0] +"'";
	for(i=1;i<count;i=i+1)
	{
		value = value+","+"'"+row[i]+"'";
	}
	string original = row[0];
	string position = original.substr(original.find("_ps")+3,original.length());
	string p1,p2;
	p1 = position.substr(0,position.find("_"));
	p2 = position.substr(position.find("_pe")+3,position.find(".")-position.find("_pe")-3);
	value = value+","+p1 + "," + p2;
  string cameraId;
  cameraId = row[0].substr(0,row[0].find("_"));
  value = value+","+"'"+cameraId+"'";

	string sql = "insert into ReId value ("+value+");";
	cout<<sql<<endl;
	MYSQL mysql;
	mysql_init(&mysql);
	mysql_real_connect(&mysql,"localhost","root","neuadmin","first",3306,NULL,0);
	mysql_query(&mysql,sql.c_str());
	mysql_close(&mysql);
}

vector<string> get_record_from_database(int position,string cameraid)
{
	vector<string> temp_result;
	vector<string> final_result;
	string sql = "select * from ReId where start<";
	sql = sql+to_string(position) +" and end > " +to_string(position)+" and cameraId = "+"'"+cameraid+"'"+" ;";
	cout<<sql<<endl;

	MYSQL mysql;
	mysql_init(&mysql);
	mysql_real_connect(&mysql,"localhost","root","neuadmin","first",3306,NULL,0);

	mysql_query(&mysql,sql.c_str());
	MYSQL_RES *result = NULL;
	result = mysql_store_result(&mysql);

	MYSQL_ROW row = NULL;
	row = mysql_fetch_row(result);
	while(NULL != row)
	{
		for(int i=1;i<6;i=i+1)
		{
			cout<<"in get_record_from_database function:  "<<row[i]<<endl;
			temp_result.push_back(row[i]);
		}
		row = mysql_fetch_row(result);
	}

	mysql_free_result(result);
	mysql_close(&mysql);

	final_result.push_back(temp_result[0]);
	bool readd=false;
	cout<<endl<<endl;
	for(int i=1;i<temp_result.size();i=i+1)
	{
		readd=false;
		for(int j=0;j<final_result.size();j=j+1)
		{
			if(temp_result[i] == final_result[j])
			{
				readd = true;
			}
		}
		if (!readd)
		{
			final_result.push_back(temp_result[i]);
		}

	}

	return final_result;
}
//dsadsa
