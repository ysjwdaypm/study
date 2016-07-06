import os
from optparse import OptionParser

def createPhoneCode(phoneCode):
	codeSet = []
	indices = []

	for code in phoneCode:
		if not code in codeSet:
			codeSet.append(code)
		index = -1
		for c in codeSet:
			index = index + 1
			if c ==  code:
				indices.append(str(index))

	str1 = "\"" + ''.join(codeSet) + "\""
	str2 = "\"" + ''.join(indices) + "\""				
	ret = "''.join([%s[int(i)] for i in %s])"%(str1,str2)
	ret = ret + "\n"
	ret = ret + "string.gsub(%s,\"%s\",function(i)return string.sub(%s,tonumber(i)+1,tonumber(i)+1) end)"%(str2,"%d",str1)
	return ret


if __name__ == "__main__":
    opt = OptionParser()
    opt.add_option("-n","--phone",dest="phone")
    (option,args) = opt.parse_args()

    codeNum = "12345678910"
    if option.phone:
        codeNum = option.phone
    else:
    	#print("")
     	codeNum = raw_input("please input you phoneCode\n")

    ret = createPhoneCode(codeNum)
    print(ret)    
