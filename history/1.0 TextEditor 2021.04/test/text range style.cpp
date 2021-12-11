
/*

interface example (in pseudo code) for TextBlock and TextRangeStyle

*/

class SomeTypeOfButtonOrSelector{
	
	...
	
	virtual void OnClick(){
		GetTextEditor.SetStyleForCurrentSelection(some_specific_style/a_list_of_styles);
	}
	
	...
	
}


class TextEditor{
	
	
	/* get the style list of current pointed text (The text position when mouse is pressed) */
	void GetCurrentSelectionStyle(){
		
		in TextBlock{
			vector<style> ;
			for all style types
				if(style = type.getstyleat(pos)){
					vec.push_back(style.clone());
				} else{
					use_default_style
					
					/* so default style can be optimized from list */
				}
		}
		
	}
	
	
}


class TextBlock{
	
	wstring text;
	
	
	void SaveTextStyles
	
	
}