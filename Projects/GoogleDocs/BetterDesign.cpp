#include<iostream>
#include<vector>
#include<string>
#include<fstream>
using namespace std ; 

class DocumentElement{
public:
    virtual string render() = 0 ; 
};
class TextElemet : public DocumentElement {
    private : 
    string text ; 
    public : 
    TextElemet(string text){
        this->text = text ; 
    }
    string render(){
        return text; 
    }
};
class ImageElement : public DocumentElement{
    private:
    string path ; 
    public : 
    ImageElement(string path){
        this->path = path; 
    }
    string render(){
        return "Image : [" + path + "]" ; 
    }
};

//ideas that we can add new elements 
class NewLineElement : public DocumentElement{
    public : 
    string render(){
        return "\n";
    }
};

class Persistence {
    public : 
    virtual void save(string data) = 0 ; 
};

class SaveToFile : public Persistence{
    public : 
    void save(string data){
        ofstream file ("document.txt");
        if(file.is_open()){
            file<<data;
            file.close();
        }
        cout<<"saved to file ...."<<endl;
    }
};

class SaveToDB : public Persistence {
    void save(string data){ 
        cout<<"saving to db .... "<<data<<endl;
    }
};  
class Document{
    vector<DocumentElement*> elements ;
public : 
     
    void addElement(DocumentElement* ele){
        elements.push_back(ele);
    }
    string render(){
        string result = "";
        for(auto ele : elements){
            result += ele->render();
        }
        return result ; 
    }
};


class DocumentEditor{
    Document* doc ; 
    Persistence* per ; 
    string renderedDoc ; 
    public : 
    DocumentEditor(Document* doc , Persistence* per){
        this->doc = doc ; 
        this-> per = per ; 
    }
    void addText(string text){
        doc->addElement(new TextElemet(text));
    }
    void addImage(string path){
        doc->addElement(new ImageElement(path));
    }
    void addNewLine(){
        doc->addElement(new NewLineElement());
    }
    string renderDoc(){
        if(renderedDoc.empty()){
            renderedDoc = doc->render();
        }
        return renderedDoc ; 
    }
    void save(){
        per->save(renderedDoc);
    }
};

int main(){
    Document* doc = new Document();
    Persistence* per = new SaveToFile();
    DocumentEditor* doced = new DocumentEditor(doc , per);
    doced->addText("hi How are you ");
    doced->addNewLine();
    doced->addImage("Photo.png");
    doced->addNewLine();
    doced->addText("kese ho yaar bata toh do ");
    cout<<doced->renderDoc();
    cout<<endl;
    doced->save();
}