#include<iostream>
#include<string>
#include<vector>
#include<fstream>
using namespace std; 

class DocumentEditor{
    public : 
    vector<string> elements ; 
    void addText(string text){
        elements.push_back(text);
    }
    void addImage(string path){
        elements.push_back(path);
    }

    string RenderDocument(){
        string result = "";
        for(auto element : elements){
            if(element.size() > 4 && (element.substr(element.size()-4) == ".png" || element.substr(element.size()-4) == ".jpg")){
                result+= "Image :["+element+"]"+"\n";
            }
            else result+=element+"\n";
        }
        return result;
    }

    void SaveToFile(){
        ofstream file("document.txt");
        if(file.is_open()){
            file<<RenderDocument();
            file.close();
            cout<<"Document saved to document.txt"<<endl;
        }
        else{
            cout<<"Error : Unable to open file for writing"<<endl;
        }
    }
};

int main(){
    DocumentEditor* editor  = new DocumentEditor(); 
    editor->addText("Hello World");
    editor->addImage("picture.jpg");
    editor->addText("This is a document editor.");
    cout<<editor->RenderDocument()<<endl;
    editor->SaveToFile();
}