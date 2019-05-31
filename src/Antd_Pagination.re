[@bs.module]
external pagination: ReasonReact.reactClass = "antd/lib/pagination";

[%bs.raw {|require("antd/lib/pagination/style")|}];

[@bs.deriving jsConverter]
type size = [ | `default | `small | `large];

[@bs.deriving jsConverter]
type btnType = [
  | `page
  | `prev
  | `next
  | [@bs.as "jump-prev"] `jumpPrev
  | [@bs.as "jump-next"] `jumpNext
];

[@bs.obj]
external makeProps:
  (
    ~total: int=?,
    ~defaultCurrent: int=?,
    ~disabled: bool=?,
    ~current: int=?,
    ~defaultPageSize: int=?,
    ~pageSize: int=?,
    ~onChange: (int, Js.Null_undefined.t(int)) => unit=?,
    ~hideOnSinglePage: bool=?,
    ~showSizeChanger: bool=?,
    ~pageSizeOptions: array(string)=?,
    ~onShowSizeChange: (int, int) => unit=?,
    ~showQuickJumper: bool=?,
    ~showTotal: (int, array(int)) => ReasonReact.reactElement=?,
    ~size: string=?,
    ~simple: bool=?,
    ~style: ReactDOMRe.Style.t=?,
    ~locale: Js.t('a)=?,
    ~className: string=?,
    ~prefixCls: string=?,
    ~selectPrefixCls: string=?,
    ~itemRender: (int, btnType, ReasonReact.reactElement) =>
                 ReasonReact.reactElement
                   =?,
    ~role: string=?,
    ~showLessItems: bool=?,
    unit
  ) =>
  _ =
  "";

let make =
    (
      ~total=?,
      ~defaultCurrent=?,
      ~disabled=?,
      ~current=?,
      ~defaultPageSize=?,
      ~pageSize=?,
      ~onChange=?,
      ~hideOnSinglePage=?,
      ~showSizeChanger=?,
      ~pageSizeOptions=?,
      ~onShowSizeChange=?,
      ~showQuickJumper=?,
      ~showTotal=?,
      ~size=?,
      ~simple=?,
      ~style=?,
      ~locale=?,
      ~className=?,
      ~prefixCls=?,
      ~selectPrefixCls=?,
      ~itemRender=?,
      ~role=?,
      ~showLessItems=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=pagination,
    ~props=
      makeProps(
        ~total?,
        ~defaultCurrent?,
        ~disabled?,
        ~current?,
        ~defaultPageSize?,
        ~pageSize?,
        ~onChange?,
        ~hideOnSinglePage?,
        ~showSizeChanger?,
        ~pageSizeOptions?,
        ~onShowSizeChange?,
        ~showQuickJumper?,
        ~showTotal?,
        ~size=?Js.Option.map((. b) => sizeToJs(b), size),
        ~simple?,
        ~style?,
        ~locale?,
        ~className?,
        ~prefixCls?,
        ~selectPrefixCls?,
        ~itemRender?,
        ~role?,
        ~showLessItems?,
        (),
      ),
    children,
  );