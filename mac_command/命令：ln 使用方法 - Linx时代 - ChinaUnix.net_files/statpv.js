document.write('<scr'+'ipt type="text/javascript" src="http://stat.it168.com/pv.js"></scr'+'ipt>');
function sendPV(){
    var pvTrack = new PvTrack();
    pvTrack.type = 10; // Ƶ�����ID
    pvTrack.channel = 22; // Ƶ��ID
   
    pvTrack.pageType = 0;
    pvTrack.track();
}
function statpv()
{
	if (PvTrack)
	{
		sendPV();
	}
	else
	{
		setTimeout("statpv()",300);
	}
}
setTimeout("statpv()",300);
document.write('<scr'+'ipt type="text/javascript" src="http://bbs.chinaunix.net/googlepv/pv.js"></scr'+'ipt>');
