#include<iostream>
#include<mysql/mysql.h>
#include<vector>

using namespace std;

vector<string> get_record_from_database(int position,string cameraid);

int main()
{
	int top[5]={1,2,3,4,5};
	for(int i=0;i<5;i=i+1)
	{
		cout<<top[i]<<endl;
	}
	// vector<string> result;
	// result = get_record_from_database(300,"first");
	// for(int i=0;i<result.size();i=i+1)
	// 	cout<<result[i]<<endl;


	// vector<string> temp_result;
	// vector<string> final_result;
	// string sql = "select * from ReId where start<";
	// int position=900;
	// string cameraid="first";
	// sql = sql+to_string(position) +" and end > " +to_string(position)+" and cameraId = "+"'"+cameraid+"'"+" ;";
	// cout<<sql<<endl;
	//
	// MYSQL mysql;
	// mysql_init(&mysql);
	// mysql_real_connect(&mysql,"localhost","root","neuadmin","first",3306,NULL,0);
	//
	// mysql_query(&mysql,sql.c_str());
	// MYSQL_RES *result = NULL;
	// result = mysql_store_result(&mysql);
	//
	// int row_count = mysql_num_rows(result);
	// cout<<"all rows: "<<row_count<<endl;
	// int fields_count = mysql_num_fields(result);
	// cout<<"all fields: "<<fields_count<<endl;
	//
	// MYSQL_ROW row = NULL;
	// row = mysql_fetch_row(result);
	// while(NULL != row)
	// {
	// 	for(int i=1;i<6;i=i+1)
	// 	{
	// 		cout<<row[i]<<endl;
	// 		temp_result.push_back(row[i]);
	// 	}
	// 	row = mysql_fetch_row(result);
	// }
	//
	// mysql_free_result(result);
	// mysql_close(&mysql);
	//
	// final_result.push_back(temp_result[0]);
	// bool readd=false;
	// cout<<endl<<endl;
	// for(int i=1;i<temp_result.size();i=i+1)
	// {
	// 	readd=false;
	// 	for(int j=0;j<final_result.size();j=j+1)
	// 	{
	// 		if(temp_result[i] == final_result[j])
	// 		{
	// 			readd = true;
	// 		}
	// 	}
	// 	if (!readd)
	// 	{
	// 		final_result.push_back(temp_result[i]);
	// 	}
	//
	// }
	// for(int i=0;i<final_result.size();i=i+1)
	// 	cout<<final_result[i]<<endl;





	// string name ="third_3986_ps3430_pe4000.PNG";
	// string position;
	// string p1,p2;
	// position = name.substr(name.find("_ps")+3,name.length());
	// p1=position.substr(0,position.find("_"));
	// p2=position.substr(position.find("_pe")+3,position.find(".")-position.find("_pe")-3);
	// cout<<position<<endl;
	// cout<<p1<<endl;
  // cout<<p2<<endl;
	//
	// int pp1,pp2;
	// pp1=stoi(p1);
	// cout<<pp1+23<<endl;

	// vector<string> row;
	// row.push_back("tssss_6_ps3430_pe4000.PNG");
	// row.push_back("bbbb");
	// row.push_back("cccc");
	// row.push_back("dddd");
	// row.push_back("dh");
	// row.push_back("sdsadsadasdasdhd");

	// insert_data2database(row);
	// row.push_back("dh");
	// row.push_back("dh");
	// insert_data2database(row);
	// distance[0] = 9.90;
	// distance[1] = 89.980;
	// cout<<distance[1]<<endl;

	// MYSQL mysql;
	// mysql_init(&mysql);
	// mysql_real_connect(&mysql,"localhost","root","neuadmin","first",3306,NULL,0);
	// string sql = "delete from ReId;";
	// cout<<sql<<endl;
	// mysql_query(&mysql,sql.c_str());
	// mysql_close(&mysql);
	// return 0;

	// MYSQL mysql;
	// mysql_init(&mysql);
	// mysql_real_connect(&mysql,"localhost","root","neuadmin","first",3306,NULL,0);
	// string sql = "select * from similar;";
	// mysql_query(&mysql,sql.c_str());
	// MYSQL_RES *result=NULL;
	// result = mysql_store_result(&mysql);
 //
	// int row_count = mysql_num_rows(result);
	// cout<<"all data number "<<row_count<<endl;
 //
	// int field_count = mysql_num_fields(result);
	// cout<<"field counts: "<<field_count<<endl;
 //
	// MYSQL_FIELD * field =NULL;
	// for(int i=0;i<field_count;i=i+1)
	// {
	// 	field = mysql_fetch_field_direct(result,i);
	// 	cout<<field->name<<endl;
	// }
	// string haha;
	// MYSQL_ROW row = NULL;
	// row = mysql_fetch_row(result);
	// while(row != NULL)
	// {
	// 	for(int i=0;i<field_count;i=i+1)
	// 	{
	// 		cout<<row[i]<<"\t";
	// 		haha = row[i];
	// 	}
	// 	cout<<endl;
	// 	row = mysql_fetch_row(result);
	// }
 //
 // cout<<haha<<endl;
	return 0;
}
