[@bs.module] external reactClass: ReasonReact.reactClass = "antd/lib/popover";

[%bs.raw {|require("antd/lib/popover/style")|}];

[@bs.obj]
external makeProps:
  (
    ~prefixCls: string=?,
    ~overlayClassName: string=?,
    ~style: ReactDOMRe.Style.t=?,
    ~overlayStyle: ReactDOMRe.Style.t=?,
    ~placement: Antd_Tooltip.placement=?,
    ~builtinPlacements: Js.Json.t=?, /* Object */
    ~defaultVisible: bool=?,
    ~visible: bool=?,
    ~onVisibleChange: bool => unit=?,
    ~mouseEnterDelay: int=?,
    ~mouseLeaveDelay: int=?,
    ~transitionName: string=?,
    ~trigger: string=?,
    ~openClassName: string=?,
    ~arrowPointAtCenter: bool=?,
    ~autoAdjustOverflow: bool=?, /* | Placement.adjustOverflow */
    /* getPopupContainer: Element => HTMLElement, */
    /* align?: TooltipAlignConfig */
    ~content: ReasonReact.reactElement=?,
    ~title: ReasonReact.reactElement=?,
    unit
  ) =>
  _ =
  "";

let make =
    (
      ~prefixCls=?,
      ~overlayClassName=?,
      ~style=?,
      ~overlayStyle=?,
      ~placement=?,
      ~builtinPlacements=?,
      ~defaultVisible=?,
      ~visible=?,
      ~onVisibleChange=?,
      ~mouseEnterDelay=?,
      ~mouseLeaveDelay=?,
      ~transitionName=?,
      ~trigger=?,
      ~openClassName=?,
      ~arrowPointAtCenter=?,
      ~autoAdjustOverflow=?,
      ~content=?,
      ~title=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      makeProps(
        ~prefixCls?,
        ~overlayClassName?,
        ~style?,
        ~overlayStyle?,
        ~placement?,
        ~builtinPlacements?,
        ~defaultVisible?,
        ~visible?,
        ~onVisibleChange?,
        ~mouseEnterDelay?,
        ~mouseLeaveDelay?,
        ~transitionName?,
        ~trigger=?
          Js.Option.map((. b) => Antd_Tooltip.triggerToJs(b), trigger),
        ~openClassName?,
        ~arrowPointAtCenter?,
        ~autoAdjustOverflow?,
        ~content?,
        ~title?,
        (),
      ),
    children,
  );