// Public domain
// http://unlicense.org/
// Created by Grigore Stefan <g_stefan@yahoo.com>

Script.requireExtension("Console");
Script.requireExtension("JSON");
Script.requireExtension("Shell");

info=Shell.fileGetContents("temp/github-release-info.json");
if(Script.isNil(info)){
	return;
};
json=JSON.decode(info);
if(Script.isNil(json)){
	return;
};

var releaseList=json["Releases"];
if(releaseList.length<=3){
	return;
};
var releaseToDelete=[];
var index;
var i;
for(i=0,index=3;index<releaseList.length;++i,++index){
	releaseToDelete[i]=releaseList[index];
};

var cmd="@echo off\n";
for(i=0;i<releaseToDelete.length;++i){
	cmd+="echo remove release "+releaseToDelete[i]["tag_name"]+"\n";
	cmd+="github-release delete --repo %GITHUB_PROJECT% --tag \""+releaseToDelete[i]["tag_name"]+"\"\n";
	cmd+="git push --delete origin \""+releaseToDelete[i]["tag_name"]+"\"\n";
};

Shell.filePutContents("temp/github-release-delete.cmd",cmd);
