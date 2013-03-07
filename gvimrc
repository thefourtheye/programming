set guioptions=
map <C-S-T> :tabnew<CR>
map <C-T> :botright vnew Scratch.txt<CR>
map <C-O> :FufFile<CR>
source $VIMRUNTIME/mswin.vim
map <C-F5> :SCCompileRun<CR> :cw<CR>
colorscheme peachpuff
set shiftwidth=3
set tabstop=3
set smartindent
map <F5> :edit<CR>
set autochdir
set autoread
syntax on
