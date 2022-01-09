colorscheme codedark
syntax enable
set tabstop=4 softtabstop=0 expandtab shiftwidth=4 smarttab
set smartindent
set number
set relativenumber
set cursorline
set incsearch
set hlsearch
syntax on
nnoremap <leader><cpace> :nohlsearch<CR>
inoremap {<CR> {<CR>}<ESC>O
inoremap {;<CR> {<CR>};<ESC>O
:autocmd BufNewFile  *.cpp 0r ~/.vim/templates/start.cpp 
:autocmd BufNewFile  *.cc 0r ~/.vim/templates/normal.cc

let &t_SI = "\<Esc>[6 q"
let &t_SR = "\<Esc>[3 q"
let &t_EI = "\<Esc>[2 q"
let g:user_emmet_leader_key='<C-Z>'

set nocompatible
filetype off

set rtp+=~/.vim/bundle/Vundle.vim
call vundle#begin()
Plugin 'VundleVim/Vundle.vim'
Plugin 'mattn/emmet-vim'
Plugin 'pangloss/vim-javascript'

call vundle#end()
filetype plugin indent on
