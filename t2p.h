typedef struct
{
  page_size_t size;
  int rotation;
  crop_t crop;
} input_attributes_t;

boolean open_tiff_input_file (char *name);
boolean close_tiff_input_file (void);


typedef struct
{
  char *author;
  char *creator;
  char *title;
  char *subject;
  char *keywords;
} pdf_file_attributes_t;

boolean open_pdf_output_file (char *name,
			      pdf_file_attributes_t *attributes);


void process_page_numbers (int page_index,
			   int count,
			   int base,
			   page_label_t *page_label);

boolean process_page (int image,  /* range 1 .. n */
		      input_attributes_t input_attributes,
		      bookmark_t *bookmarks);
