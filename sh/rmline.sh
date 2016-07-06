if [ $# -ge 1 ];then   
        for each in $@  
        do  
                if [ -f $each ];then  
                        name="tmp_$each"  
                        sed -e '/^$/d' $each >$name  
                        rm $each  
                        mv $name $each  
                else  
                        echo "rmnone:no such file $each"  
                fi  
        done  
else  
        echo "rmnone:no input file"  
        exit  
fi  

