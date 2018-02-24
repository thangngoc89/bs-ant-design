open Antd_Helpers;

[%bs.raw {|require("antd/lib/grid/style")|}];

module Row = {
  [@bs.module]
  external reactClass : ReasonReact.reactClass = "antd/lib/grid/row";

  [@bs.deriving jsConverter]
  type rowType = [ | `flex];

  [@bs.deriving jsConverter]
  type rowAlign = [ | `top | `middle | `bottom];

  [@bs.deriving jsConverter]
  type rowJustify = [
    | `start
    | `end_
    | `center
    | `spaceAround
    | `spaceBetween
  ];

  type breakpointMap = {
    .
    "xs": Js.undefined(string),
    "sm": Js.undefined(string),
    "md": Js.undefined(string),
    "lg": Js.undefined(string),
    "xl": Js.undefined(string),
    "xxl": Js.undefined(string)
  };

  [@bs.obj] external _gutterBreakpointMap: 
    (
      ~xs: string=?,
      ~sm: string=?,
      ~md: string=?,
      ~lg: string=?,
      ~xl: string=?,
      ~xxl: string=?,
      unit
    ) => 
    _ = 
    "";

  type gutterParameter = 
    | Simple(int)
    | BreakpointMap(breakpointMap);

  let simpleGutter = x => Simple(x);

  let breakpointGutter = (
    ~xs=?,
    ~sm=?,
    ~md=?,
    ~lg=?,
    ~xl=?,
    ~xxl=?,
    ()
  ): gutterParameter => {
    let map = (f, opt) =>
    switch opt {
    | Some(v) => Some(f(v))
    | None => None
    };

    BreakpointMap(_gutterBreakpointMap(
      ~xs =? xs |> map(string_of_int),
      ~sm =? sm |> map(string_of_int),
      ~md =? md |> map(string_of_int),
      ~lg =? lg |> map(string_of_int),
      ~xl =? xl |> map(string_of_int),
      ~xxl =? xxl |> map(string_of_int),
      ()
      ))
  };

  [@bs.obj]
  external makePropsGutterInt :
    (
      ~className: string=?,
      ~gutter: int=?,
      ~_type: string=?,
      ~align: string=?,
      ~justify: string=?,
      ~style: ReactDOMRe.Style.t=?,
      ~prefixCls: string=?,
      unit
    ) =>
    _ =
    "";

  [@bs.obj]
  external makePropsGutterObj :
    (
      ~className: string=?,
      ~gutter:breakpointMap =?,
      ~_type: string=?,
      ~align: string=?,
      ~justify: string=?,
      ~style: ReactDOMRe.Style.t=?,
      ~prefixCls: string=?,
      unit
    ) =>
    _ =
    "";
    
  let make =
    (
      ~className=?,
      ~gutter=?,
      ~_type=?,
      ~align=?,
      ~justify=?,
      ~style=?,
      ~prefixCls=?,
      children
    ) =>
    switch gutter {
    | Some(Simple(gutterInt)) => {
      ReasonReact.wrapJsForReason(
        ~reactClass,
        ~props=
          makePropsGutterInt(
            ~className?,
            ~gutter=gutterInt,
            ~_type=?Js.Option.map([@bs] (b => rowTypeToJs(b)), _type),
            ~align=?Js.Option.map([@bs] (b => rowAlignToJs(b)), align),
            ~justify=?Js.Option.map([@bs] (b => rowJustifyToJs(b)), justify),
            ~style?,
            ~prefixCls?,
            ()
          ),
        children
      );
    }
    | Some(BreakpointMap(breakpointMap)) => {
      ReasonReact.wrapJsForReason(
          ~reactClass,
          ~props=
            makePropsGutterObj(
              ~className?,
              ~gutter=breakpointMap,
              ~_type=?Js.Option.map([@bs] (b => rowTypeToJs(b)), _type),
              ~align=?Js.Option.map([@bs] (b => rowAlignToJs(b)), align),
              ~justify=?Js.Option.map([@bs] (b => rowJustifyToJs(b)), justify),
              ~style?,
              ~prefixCls?,
              ()
            ),
          children
        );
    }
    | None => 
    ReasonReact.wrapJsForReason(
        ~reactClass,
        ~props=
          makePropsGutterObj(
            ~className?,
            ~_type=?Js.Option.map([@bs] (b => rowTypeToJs(b)), _type),
            ~align=?Js.Option.map([@bs] (b => rowAlignToJs(b)), align),
            ~justify=?Js.Option.map([@bs] (b => rowJustifyToJs(b)), justify),
            ~style?,
            ~prefixCls?,
            ()
          ),
        children
      );
    };
};