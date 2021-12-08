# findpeaks
matlab findpeaks(signal,'minpeakdistance",mpd) in C++.  
This function finds peaks separated by more than the minimum peak distance, MPD.   
This parameter may bespecified to ignore smaller peaks that may occur in close proximity toa large local peak.   
For example, if a large local peak occurs at LOC,then all smaller peaks in the range [N-MPD, N+MPD] are ignored.   
If notspecified, MPD is assigned a value of zero.   
